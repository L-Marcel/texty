#include "enum.hpp"

// Debug
void EnumNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "ENUM: " + this->name.substr(4));
  for (size_t i = 0; i < this->values.size(); i++) {
    Compiler::add_dot_node_item(os, this, this->values[i].substr(4));
  };
};

// Código
void EnumNode::compile_code(ostream& os) const {
  string fallback_value = this->values.size() > 0
                              ? this->name + "_" + this->values[0].substr(4)
                              : this->name + "_EMPTY";

  generated_declarations << std::endl
                            << "enum " << this->name << " {" << std::endl;
  if (this->values.size() == 0) {
    generated_declarations << "\t" << fallback_value << std::endl;
  } else {
    for (size_t i = 0; i < this->values.size(); i++) {
      generated_declarations << "\t" << this->name << "_"
                                << this->values[i].substr(4);
      if (i != this->values.size() - 1) generated_declarations << ",";
      generated_declarations << std::endl;
    };
  }
  generated_declarations << "};" << std::endl;

  // Default
  generated_implementations << this->name << " " << this->name
                            << "_default() {" << std::endl;
  generated_implementations << "\treturn " << fallback_value << ";"
                            << std::endl;
  generated_implementations << "};" << std::endl;

  // Compare
  generated_implementations << "int " << this->name << "_compare("
                            << this->name << " a, " << this->name
                            << " b) {" << std::endl;
  generated_implementations << "\treturn EQUALS(a, b);" << std::endl;
  generated_implementations << "};" << std::endl;

  // String
  generated_implementations << "char* " << this->name << "_to_string("
                            << this->name << " instance) {" << std::endl;
  for (size_t i = 0; i < this->values.size(); i++) {
    generated_implementations << "\tif (!EQUALS(instance, " << this->name
                              << "_" << this->values[i].substr(4)
                              << ")) goto value_" << i << "_end;"
                              << std::endl;
    generated_implementations << "\treturn (char*)(\""
                              << this->values[i].substr(4) << "\");"
                              << std::endl;
    generated_implementations << "value_" << i << "_end:" << std::endl;
  };
  generated_implementations << "\treturn (char*)(\"\");" << std::endl;
  generated_implementations << "};" << std::endl;

  // Index
  generated_implementations << this->name << " " << this->name
                            << "_from_int(int32_t index) {" << std::endl;
  if (this->values.size() > 0) {
    generated_implementations << "\tindex = index % ((int32_t)"
                              << this->values.size() << ");" << std::endl;
    generated_implementations
        << "\tif (!(index < ((int32_t)0))) goto positive_index;" << std::endl;
    generated_implementations << "\tindex = index + ((int32_t)"
                              << this->values.size() << ");" << std::endl;
    generated_implementations << "positive_index:" << std::endl;
    for (size_t i = 0; i < this->values.size(); i++) {
      generated_implementations << "\tif (!EQUALS(index, ((int32_t)" << i
                                << "))) goto index_" << i << "_end;"
                                << std::endl;
      generated_implementations << "\treturn " << this->name << "_"
                                << this->values[i].substr(4) << ";"
                                << std::endl;
      generated_implementations << "index_" << i << "_end:" << std::endl;
    };
  }
  generated_implementations << "\treturn " << fallback_value << ";"
                            << std::endl;
  generated_implementations << "};" << std::endl;
};

// Tipagem
Type EnumNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
EnumNode::EnumNode(int line, string name, vector<string> values)
    : Node(line, name), values(values) {};
