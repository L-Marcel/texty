#include "enum.hpp"

// Debug
void EnumNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "ENUM: " + this->name);
  for (size_t i = 0; i < this->values.size(); i++) {
    Compiler::add_dot_node_item(os, this, this->values[i]);
  };
};

// Código
void EnumNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type EnumNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
EnumNode::EnumNode(int line, string name, vector<string> values)
    : Node(line, name), values(values) {};