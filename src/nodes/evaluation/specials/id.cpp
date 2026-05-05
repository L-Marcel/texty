#include "id.hpp"

#include "../../../references/references.hpp"

// Debug
void IdNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, this->name);
};

// Código
void IdNode::compile_code(ostream& os) const {
  // TODO
};

// Referência
Reference* IdNode::get_reference() const {
  return References::get_instance()->get_reference(this->name);
};

// Construtores
IdNode::IdNode(int line, string name) : ExpressionNode(line), name(name) {};