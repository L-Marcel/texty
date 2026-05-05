#include "main.hpp"

#include "lex.yy.h"
#include "nodes/compiler.hpp"
#include "syntax.tab.hh"

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
    std::cerr << "[ERRO] Não foi possível abrir " << filename << std::endl;
    return 1;
  } else if (mime != "txy") {
    std::cerr << "[ERRO] Extensão inválida do arquivo " << filename
              << std::endl;
    return 1;
  };

  yyrestart(source);

  Context ctx;
  yy::parser parser = yy::parser(ctx);

  try {
    int result = parser.parse();

    if (result == 0) {
      std::cout << "[INFO] Arvore sintática montada sem erros" << std::endl;
      std::cout << "[INFO] Compilando arquivos" << std::endl;
      Compiler::create_dot(ctx, filename);
      Compiler::create_code(ctx, filename);
      fclose(source);
    } else {
      std::cerr << "[ERRO] Falha na compilacao" << std::endl;
    };

    return result;
  } catch (const error& e) {
    std::cerr << e.what() << std::endl;
    return 0;
  } catch (const std::exception& e) {
    std::cerr << "[ERRO CRÍTICO] " << e.what() << std::endl;
    return 0;
  }
};
