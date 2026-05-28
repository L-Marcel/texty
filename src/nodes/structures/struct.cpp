#include "struct.hpp"

// Debug
void StructNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "STRUCT: " + this->name);
  for (size_t i = 0; i < this->attributes.size(); i++) {
    Attribute attribute = this->attributes.at(i);
    string label = attribute.first + ": " + attribute.second.to_string();
    Compiler::add_dot_node_item(os, this, label);
  };
};

// Código
void StructNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type StructNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
StructNode::StructNode(int line, string name, vector<Attribute> attributes)
    : Node(line, name), attributes(attributes) {};