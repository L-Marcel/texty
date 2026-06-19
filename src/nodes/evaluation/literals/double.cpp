#include "double.hpp"

#include "../../../lib/magic_enum.hpp"

// Debug
void DoubleNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->get_type().kind)) +
                             ": " + to_string(this->value));
};

// Código
void DoubleNode::compile_code(ostream& os) const { os << this->value; };

// Tipagem
Type DoubleNode::get_type() const { return Type(TypeKind::DOUBLE); };

// Construtores
DoubleNode::DoubleNode(int line, double value)
    : ExpressionNode(line), value(value) {};
