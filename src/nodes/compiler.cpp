#include "compiler.hpp"

// Filename
string get_filename_without_mime(string filename) {
  int index = filename.rfind('.');
  if (index < 0) return "";
  return filename.substr(0, index);
};

// Dot
void Compiler::add_dot_node(ostream& os, const Node* node, string label) {
  os << "  \"" << node << "\" [label=\"" << label << "\"];" << std::endl;
};
void Compiler::add_dot_relation(ostream& os, const Node* from, Node* to) {
  os << "  \"" << from << "\" -> \"" << to << "\";" << std::endl;
  to->compile_dot(os);
};
void Compiler::create_dot(Context& ctx, string filename) {
  ofstream file = ofstream(get_filename_without_mime(filename) + ".dot");
  std::cout << "[DEBUG] Montando arquivo de visualização" << std::endl;
  if (file.is_open()) {
    file << "digraph AST {" << std::endl;
    file << "  node [shape=box, fontname=\"Courier\"];" << std::endl;

    if (ctx.root != nullptr) {
      ctx.root->compile_dot(file);
    }

    file << "}" << std::endl;
    file.close();
    std::cout << "[DEBUG] Arquivo de visualização montado" << std::endl;
  } else {
    std::cerr << "[ERRO] Não foi possível montar o arquivo de visualização"
              << std::endl;
  }
};

// Código
void Compiler::create_code(Context& ctx, string filename) {

};