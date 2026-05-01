#include "dot.hpp"

void Dot::create(Context& ctx) {
  ofstream file = ofstream("ast.dot");
  std::cout << "[DEBUG] Montando arquivo de visualização" << std::endl;
  if (file.is_open()) {
    file << "digraph AST {" << std::endl;
    file << "  node [shape=box, fontname=\"Courier\"];" << std::endl;

    if (ctx.root != nullptr) {
      ctx.root->print(file);
    }

    file << "}" << std::endl;
    file.close();
    std::cout << "[DEBUG] Arquivo de visualização montado" << std::endl;
  } else {
    std::cerr << "[ERRO] Não foi possível montar o arquivo de visualização"
              << std::endl;
  }
};