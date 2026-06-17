#include "struct.hpp"

// Debug
void StructNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "STRUCT: " + this->name.substr(4));
  for (size_t i = 0; i < this->attributes.size(); i++) {
    pair<string, Type> attribute = this->attributes[i];
    string label = attribute.first + ": " + attribute.second.to_string();
    Compiler::add_dot_node_item(os, this, label);
  };
};

// Código
void StructNode::compile_code(ostream& os) const {
  for (size_t i = 0; i < this->attributes.size(); i++) {
    this->attributes[i].second.get_name();
  };

  generated_code << std::endl << "struct " << this->name << " {" << std::endl;
  for (size_t i = 0; i < this->attributes.size(); i++) {
    pair<string, Type> attribute = this->attributes[i];
    generated_code << "\t" << attribute.second.to_production() << " "
                   << attribute.first << ";" << std::endl;
  };
  generated_code << "};" << std::endl;

  // Default
  generated_code << this->name << " " << this->name << "_default() {"
                 << std::endl;
  generated_code << "\t" << this->name << " instance;" << std::endl;
  for (size_t i = 0; i < this->attributes.size(); i++) {
    pair<string, Type> attribute = this->attributes[i];
    generated_code << "\tinstance." << attribute.first << " = "
                   << attribute.second.get_default_value() << ";" << std::endl;
  }
  generated_code << "\treturn instance;" << std::endl;
  generated_code << "};" << std::endl;

  // Compare
  generated_code << "int " << this->name << "_compare(" << this->name << " a, "
                 << this->name << " b) {" << std::endl;
  for (size_t i = 0; i < this->attributes.size(); i++) {
    pair<string, Type> attribute = this->attributes[i];
    TypeKind kind = attribute.second.kind;
    if (kind == TypeKind::ARRAY || kind == TypeKind::OPTION ||
        kind == TypeKind::RANGE || kind == TypeKind::NAMED) {
      generated_code << "\tif (!" << attribute.second.get_name()
                     << "_compare(a." << attribute.first << ", b."
                     << attribute.first << ")) goto not_equals;" << std::endl;
    } else {
      generated_code << "\tif (!EQUALS(a." << attribute.first << ", b."
                     << attribute.first << ")) goto not_equals;" << std::endl;
    };
  };
  generated_code << "\treturn 1;" << std::endl << std::endl;
  generated_code << "not_equals:" << std::endl;
  generated_code << "\treturn 0;" << std::endl;
  generated_code << "};" << std::endl;

  // String
  generated_code << "char* " << this->name << "_to_string(" << this->name
                 << " instance) {" << std::endl;
  generated_code << "\tarray_string props = array_string_create("
                 << this->attributes.size() << ", \"\");" << std::endl;
  for (size_t i = 0; i < this->attributes.size(); i++) {
    pair<string, Type> attribute = this->attributes[i];
    generated_code << "\tprops.pointer[" << i
                   << "] = " << attribute.second.get_name()
                   << "_to_string(instance." << attribute.first << ");"
                   << std::endl;
  }
  generated_code << "\treturn txy_join(\", \", props);" << std::endl;
  generated_code << "};" << std::endl;
};

// Tipagem
Type StructNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
StructNode::StructNode(int line, string name,
                       vector<pair<string, Type>> attributes)
    : Node(line, name), attributes(attributes) {};
