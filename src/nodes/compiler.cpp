#include "compiler.hpp"

#include "../embedded_standard.hpp"

stringstream generated_implementations;
stringstream generated_declarations;
stringstream generated_type_implementations;
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

    string compare_function = "EQUALS";
    if (inner_type.kind == TypeKind::ARRAY ||
        inner_type.kind == TypeKind::OPTION ||
        inner_type.kind == TypeKind::RANGE ||
        inner_type.kind == TypeKind::NAMED) {
      compare_function = inner_type.get_name() + "_compare";
    };

    string to_string_function = name + "_to_string";
    if (inner_type.kind == TypeKind::POINTER) {
      to_string_function = "pointer_to_string";
    };

    generated_declarations << "DECLARE_ARRAY(";
    generated_declarations << inner_type.to_production();
    generated_declarations << ", " << name << ")" << std::endl;

    generated_type_implementations << "IMPLEMENT_ARRAY(";
    generated_type_implementations << inner_type.to_production();
    generated_type_implementations << ", " << name << ", " << compare_function
                                   << ", ";
    generated_type_implementations << to_string_function;
    generated_type_implementations << ")" << std::endl;
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

    string compare_functiontion = "EQUALS";
    if (inner_type.kind == TypeKind::ARRAY ||
        inner_type.kind == TypeKind::OPTION ||
        inner_type.kind == TypeKind::RANGE ||
        inner_type.kind == TypeKind::NAMED) {
      compare_functiontion = inner_type.get_name() + "_compare";
    };

    string to_string_function = name + "_to_string";
    if (inner_type.kind == TypeKind::POINTER) {
      to_string_function = "pointer_to_string";
    };

    generated_declarations << "DECLARE_OPTION(";
    generated_declarations << inner_type.to_production();
    generated_declarations << ", " << name << ")" << std::endl;

    generated_type_implementations << "IMPLEMENT_OPTION(";
    generated_type_implementations << inner_type.to_production();
    generated_type_implementations << ", " << name << ", "
                                   << compare_functiontion << ", ";
    generated_type_implementations << to_string_function;
    generated_type_implementations << ")" << std::endl;
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
    };

    file << "}" << std::endl;
    file.close();
    std::cout << DEBUG_LABEL << "Arquivo de visualização montado" << std::endl;
  } else {
    std::cerr << ERROR_LABEL
              << "Não foi possível montar o arquivo de visualização"
              << std::endl;
  };
};

// Código
void Compiler::create_code(Context& ctx, string filename) {
  string base_filename = get_filename_without_mime(filename);
  string cpp_filename = base_filename + ".c";
  ofstream file = ofstream(cpp_filename);
  std::cout << DEBUG_LABEL << "Montando arquivo intermediário" << std::endl;

  if (file.is_open()) {
    generated_implementations.str("");
    generated_implementations.clear();
    generated_declarations.str("");
    generated_declarations.clear();
    generated_type_implementations.str("");
    generated_type_implementations.clear();
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
    file << "// ================ DECLARATIONS ================ //" << std::endl;
    file << "// ---------------------------------------------- //" << std::endl;
    file << std::endl << generated_declarations.str() << std::endl << std::endl;
    file << "// ---------------------------------------------- //" << std::endl;
    file << "// =============== IMPLEMENTATIONS ============== //" << std::endl;
    file << "// ---------------------------------------------- //" << std::endl;
    file << std::endl
         << std::endl
         << generated_implementations.str() << std::endl
         << std::endl;
    file << "// ---------------------------------------------- //" << std::endl;
    file << "// ============ TYPE IMPLEMENTATIONS ============ //" << std::endl;
    file << "// ---------------------------------------------- //" << std::endl;
    file << std::endl
         << std::endl
         << generated_type_implementations.str() << std::endl
         << std::endl;
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
        "gcc -O2 " + cpp_filename + " -o " + output_filename + " -lm";

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