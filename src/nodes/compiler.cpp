#include "compiler.hpp"

#include "../embedded_standard.hpp"

stringstream generated_code;
set<string> Compiler::defined_arrays = {"string", "char", "bool",  "byte",
                                        "int",    "long", "float", "double"};
set<string> Compiler::defined_options = {"string", "char", "bool",  "byte",
                                         "int",    "long", "float", "double"};

// Registro de tipos
void Compiler::register_array(Type inner_type) {
  string name = inner_type.get_name();
  if (defined_arrays.find(name) == defined_arrays.end()) {
    defined_arrays.insert(name);

    if (inner_type.kind == TypeKind::ARRAY) {
      register_array(*inner_type.inner_type);
    } else if (inner_type.kind == TypeKind::OPTION) {
      register_option(*inner_type.inner_type);
    };

    generated_code << "DEFINE_ARRAY(";
    generated_code << inner_type.to_production();
    generated_code << ", " << name << ", EQUALS, ";
    generated_code << name << "_to_string";
    generated_code << ")" << std::endl;
  };
};

void Compiler::register_option(Type inner_type) {
  string name = inner_type.get_name();
  if (defined_options.find(name) == defined_options.end()) {
    defined_options.insert(name);

    if (inner_type.kind == TypeKind::ARRAY) {
      register_array(*inner_type.inner_type);
    } else if (inner_type.kind == TypeKind::OPTION) {
      register_option(*inner_type.inner_type);
    };

    generated_code << "DEFINE_OPTION(";
    generated_code << inner_type.to_production();
    generated_code << ", " << name << ", ";
    generated_code << name << "_to_string";
    generated_code << ")" << std::endl;
  };
};

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
void Compiler::add_dot_node_item(ostream& os, const Node* node, string item) {
  os << "  \"" << node << "_" << item << "\" [label=\"" << item << "\"];"
     << std::endl;
  os << "  \"" << node << "\" -> \"" << node << "_" << item << "\";"
     << std::endl;
};
void Compiler::add_dot_node_item_relation(ostream& os, const Node* node,
                                          string item, const Node* to) {
  os << "  \"" << node << "_" << item << "\" -> \"" << to << "\";" << std::endl;
  to->compile_dot(os);
};
void Compiler::add_dot_relation(ostream& os, const Node* from, const Node* to) {
  os << "  \"" << from << "\" -> \"" << to << "\";" << std::endl;
  to->compile_dot(os);
};
void Compiler::create_dot(Context& ctx, string filename) {
  ofstream file = ofstream(get_filename_without_mime(filename) + ".dot");
  std::cout << DEBUG_LABEL << "Montando arquivo de visualização" << std::endl;
  if (file.is_open()) {
    file << "digraph AST {" << std::endl;
    file << "  node [shape=box, fontname=\"Courier\"];" << std::endl;

    if (ctx.root != nullptr) {
      ctx.root->compile_dot(file);
    }

    file << "}" << std::endl;
    file.close();
    std::cout << DEBUG_LABEL << "Arquivo de visualização montado" << std::endl;
  } else {
    std::cerr << ERROR_LABEL
              << "Não foi possível montar o arquivo de visualização"
              << std::endl;
  }
};

// Código
void Compiler::create_code(Context& ctx, string filename) {
  string base_filename = get_filename_without_mime(filename);
  string cpp_filename = base_filename + ".c";
  ofstream file = ofstream(cpp_filename);
  std::cout << DEBUG_LABEL << "Montando arquivo intermediário" << std::endl;

  if (file.is_open()) {
    generated_code.str("");
    generated_code.clear();
    Compiler::defined_arrays = {"string", "char", "bool",  "byte",
                                "int",    "long", "float", "double"};
    Compiler::defined_options = {"string", "char", "bool",  "byte",
                                 "int",    "long", "float", "double"};

    stringstream program;
    if (ctx.root != nullptr) {
      ctx.root->compile_code(program);
    };

    file << "// ================== STANDARD ================== //" << std::endl;
    file << "// ---------------------------------------------- //" << std::endl;
    file << std::endl << TEXTY_STANDARD_LIBRARY << std::endl << std::endl;
    file << "// ---------------------------------------------- //" << std::endl;
    file << "// ================== GENERATED ================= //" << std::endl;
    file << "// ---------------------------------------------- //" << std::endl;
    file << std::endl << generated_code.str() << std::endl << std::endl;
    file << "// ---------------------------------------------- //" << std::endl;
    file << "// ================== PROGRAM =================== //" << std::endl;
    file << "// ---------------------------------------------- //" << std::endl;
    file << std::endl << program.str() << std::endl << std::endl;

    file.close();
    std::cout << DEBUG_LABEL << "Arquivo de intermediário montado" << std::endl;
    std::cout << DEBUG_LABEL << "Compilando binário final" << std::endl;

#ifdef _WIN32
    string output_filename = base_filename + ".exe";
#else
    string output_filename = base_filename;
#endif

    string command =
        "g++ -O2 -std=c++17 " + cpp_filename + " -o " + output_filename;

    int result = std::system(command.c_str());

    if (result == 0) {
      std::cout << SUCCESS_LABEL << "Binário final compilado com sucesso"
                << std::endl;
    } else {
      std::cerr << ERROR_LABEL << "Falha ao compilar binário final"
                << std::endl;
    }
  } else {
    std::cerr << ERROR_LABEL
              << "Não foi possível montar o arquivo intermediário" << std::endl;
  }
};