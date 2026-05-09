#include "option.hpp"

// Debug
void OptionNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "OPTION");
}

// Código
void OptionNode::compile_code(ostream& os) const {
  // TODO
}

// Tipagem
Type OptionNode::get_type() const {
  return Type(TypeKind::OPTION, new Type(TypeKind::UNKNOWN));
};

// Construtores
OptionNode::OptionNode(int line, Option value)
    : ExpressionNode(line), value(value) {};