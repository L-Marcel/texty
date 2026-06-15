#include "continue.hpp"

// Debug
void ContinueNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "CONTINUE");
};

// Código
void ContinueNode::compile_code(ostream& os) const {
  // TODO - Break só pode dentro de loop, mesma coisa do break
  // (não tente)
  os << "continue";
};

// Tipagem
Type ContinueNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
ContinueNode::ContinueNode(int line) : Node(line) {};