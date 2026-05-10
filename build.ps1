# Configurações
$CXX = "g++"
$CXXFLAGS = "-std=c++17", "-Wall", "-I.", "-I./src", "-Igrammar/build", "-Iexternal/magic_enum/include"
$TARGET = "texty.exe"

# Diretórios
$BUILD_DIR = "build"
$GRAMMAR_DIR = "grammar"
$GRAMMAR_BUILD_DIR = "$GRAMMAR_DIR/build"

# Arquivos gerados
$BISON_CC = "$GRAMMAR_BUILD_DIR/syntax.tab.cc"
$BISON_HH = "$GRAMMAR_BUILD_DIR/syntax.tab.hh"
$FLEX_C = "$GRAMMAR_BUILD_DIR/lex.yy.c"

# Garante que as pastas existam
if (-not (Test-Path $BUILD_DIR)) { New-Item -ItemType Directory -Path $BUILD_DIR }
if (-not (Test-Path $GRAMMAR_BUILD_DIR)) { New-Item -ItemType Directory -Path $GRAMMAR_BUILD_DIR }

Write-Host "[ 1/3 ] Gerando analisadores Léxico e Sintático (WinFlexBison)..." -ForegroundColor Cyan
win_bison -d "$GRAMMAR_DIR/syntax.y" -o "$BISON_CC"
win_flex -o "$FLEX_C" "$GRAMMAR_DIR/lexical.l"

Write-Host "[ 2/3 ] Buscando código fonte..." -ForegroundColor Cyan
$SRCS = Get-ChildItem -Path src -Filter *.cpp -Recurse | ForEach-Object { $_.FullName }
$ALL_SRCS = $SRCS + $BISON_CC + $FLEX_C

Write-Host "[ 3/3 ] Compilando o projeto..." -ForegroundColor Cyan
& $CXX $CXXFLAGS $ALL_SRCS -o $TARGET

if ($LASTEXITCODE -eq 0) {
    Write-Host "✅ Build concluído com sucesso! Executável gerado: $TARGET" -ForegroundColor Green
} else {
    Write-Host "❌ Erro durante a compilação." -ForegroundColor Red
    exit 1
}
