#include "main.hpp"

#include "dot.hpp"
#include "syntax.tab.hh"

int main() {
  Context ctx;
  yy::parser parser = yy::parser(ctx);

  std::cout << "Digite seu codigo (Ctrl+D para encerrar):" << std::endl;

  try {
    int resultado = parser.parse();

    if (resultado == 0) {
      std::cout << "[INFO] Arvore sintática montada sem erros" << std::endl;
      Dot::create(ctx);
    } else {
      std::cerr << "[ERRO] Falha na compilacao" << std::endl;
    };

    return resultado;
  } catch (const error& e) {
    std::cerr << e.what() << std::endl;
    return 0;
  } catch (const std::exception& e) {
    std::cerr << "[ERRO CRÍTICO] " << e.what() << std::endl;
    return 0;
  }
};
