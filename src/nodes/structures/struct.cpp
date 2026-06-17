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
  os << std::endl
     << "typedef struct " << this->name << " " << this->name << ";"
     << std::endl;
  os << "struct " << this->name << " {" << std::endl;
  for (size_t i = 0; i < this->attributes.size(); i++) {
    pair<string, Type> attribute = this->attributes[i];
    os << "\t" << attribute.second.to_production() << " " << attribute.first
       << ";" << std::endl;
  };
  os << "};" << std::endl;

  // Default
  os << this->name << " " << this->name << "_default() {" << std::endl;
  os << "\t" << this->name << " instance;" << std::endl;
  for (size_t i = 0; i < this->attributes.size(); i++) {
    pair<string, Type> attribute = this->attributes[i];
    os << "\tinstance." << attribute.first << " = "
       << attribute.second.get_default_value() << ";" << std::endl;
  }
  os << "\treturn instance;" << std::endl;
  os << "};" << std::endl;

  // Compare
  os << "int " << this->name << "_compare(" << this->name << " a, "
     << this->name << " b) {" << std::endl;
  for (size_t i = 0; i < this->attributes.size(); i++) {
    pair<string, Type> attribute = this->attributes[i];
    TypeKind kind = attribute.second.kind;
    if (kind == TypeKind::ARRAY || kind == TypeKind::OPTION ||
        kind == TypeKind::RANGE || kind == TypeKind::NAMED) {
      os << "\tif (!" << attribute.second.get_name() << "_compare(a."
         << attribute.first << ", b." << attribute.first
         << ")) goto not_equals;" << std::endl;
    } else {
      os << "\tif (!EQUALS(a." << attribute.first << ", b." << attribute.first
         << ")) goto not_equals;" << std::endl;
    };
  };

  os << std::endl << "equals:" << std::endl;
  os << "\treturn 1;" << std::endl << std::endl;
  os << "not_equals:";
  os << "\treturn 0;" << std::endl;
  os << "};" << std::endl;

  // String
  os << "char* " << this->name << "_to_string(" << this->name << " instance) {"
     << std::endl;
  os << "\tarray_string props = array_string_create(" << this->attributes.size()
     << ", \"\");" << std::endl;
  for (size_t i = 0; i < this->attributes.size(); i++) {
    pair<string, Type> attribute = this->attributes[i];
    os << "\tprops.pointer[" << i << "] = " << attribute.second.get_name()
       << "_to_string(instance." << attribute.first << ");" << std::endl;
  }
  os << "\treturn txy_join(\", \", props);" << std::endl;
  os << "};" << std::endl;
};

// Tipagem
Type StructNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
StructNode::StructNode(int line, string name,
                       vector<pair<string, Type>> attributes)
    : Node(line, name), attributes(attributes) {};
