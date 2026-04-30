#include <fstream>
#include <iostream>

#include "context.h"
#include "syntax.tab.hh"

void print_ast(Context& context) {
  ofstream file = ofstream("ast.dot");

  if (file.is_open()) {
    file << "digraph AST {" << std::endl;
    file << "  node [shape=box, fontname=\"Courier\"];" << std::endl;

    if (context.root != nullptr) {
      context.root->print(file);
    }

    file << "}" << std::endl;
    file.close();
    std::cout << "Arquivo da árvore sintática atualizado." << std::endl;
  } else {
    std::cerr << "Não foi possível abrir o arquivo." << std::endl;
  }
};

int main() {
  Context context;
  yy::parser parser = yy::parser(context);

  std::cout << "Digite seu codigo (Ctrl+D para encerrar):" << std::endl;

  int resultado = parser.parse();

  if (resultado == 0) {
    print_ast(context);
    std::cout << "Arvore sintática montada sem erros!" << std::endl;
  } else {
    std::cerr << "Falha na compilacao." << std::endl;
  };

  return resultado;
};

void yy::parser::error(const std::string& msg) {
  std::cerr << "Erro de síntaxe: " << msg << std::endl;
};