#include "main.hpp"

#include "lex.yy.h"
#include "nodes/compiler.hpp"
#include "syntax.tab.hh"

#ifdef _WIN32
#include <windows.h>
void setup_terminal_colors() {
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  if (hOut == INVALID_HANDLE_VALUE) return;

  DWORD dwMode = 0;
  if (!GetConsoleMode(hOut, &dwMode)) return;

  dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(hOut, dwMode);
}
#else
void setup_terminal_colors() {}
#endif

extern void yyrestart(FILE* input_file);

string get_mime(string filename) {
  int index = filename.rfind('.');
  if (index < 0) return "";
  return filename.substr(index + 1);
};

int main(int argc, char** argv) {
  CLI::App app = CLI::App{"Texty Compiler"};

  string filename;

  app.add_option("-f,--file", filename, "Require an existing file")
      ->required()
      ->check(CLI::ExistingFile);

  CLI11_PARSE(app, argc, argv);

  string mime = get_mime(filename);
  FILE* source = fopen(filename.c_str(), "r");
  if (!source) {
    std::cerr << ERROR_LABEL << "Não foi possível abrir " << filename
              << std::endl;
    return 1;
  } else if (mime != "txy") {
    std::cerr << ERROR_LABEL << "Extensão inválida do arquivo " << filename
              << std::endl;
    return 1;
  };

  yyrestart(source);

  Context ctx;
  yy::parser parser = yy::parser(ctx);

  try {
    int result = parser.parse();

    if (result == 0) {
      std::cout << INFO_LABEL << "Arvore sintática montada sem erros"
                << std::endl;
      std::cout << DEBUG_LABEL << "Compilando arquivos" << std::endl;
      Compiler::create_dot(ctx, filename);
      Compiler::create_code(ctx, filename);
      fclose(source);
    } else {
      std::cerr << ERROR_LABEL << "Falha na compilacao" << std::endl;
    };

    return result;
  } catch (const error& e) {
    std::cerr << e.what() << std::endl;
    return 0;
  } catch (const std::exception& e) {
    std::cerr << FATAL_LABEL << e.what() << std::endl;
    return 0;
  }
};
