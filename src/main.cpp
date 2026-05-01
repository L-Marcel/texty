#include "main.hpp"

#include "syntax.tab.hh"

int main() {
  Context ctx;
  yy::parser parser = yy::parser(ctx);

  std::cout << "Digite seu codigo (Ctrl+D para encerrar):" << std::endl;

  int resultado = parser.parse();

  if (resultado == 0) {
    std::cout << "[INFO] Arvore sintática montada sem erros" << std::endl;
    print_ast(ctx);
  } else {
    std::cerr << "[ERRO] Falha na compilacao" << std::endl;
  };

  return resultado;
};
