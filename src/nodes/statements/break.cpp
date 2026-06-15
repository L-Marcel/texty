#include "break.hpp"

// Debug
void BreakNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "BREAK");
};

// Código
void BreakNode::compile_code(ostream& os) const {
  // TODO - Break só pode dentro de loop
  // (não tente)
  os << "break";
};

// Tipagem
Type BreakNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
BreakNode::BreakNode(int line) : Node(line) {};