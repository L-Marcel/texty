#include "double.hpp"

// Debug
void DoubleNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->get_type())) +
                             ": " + to_string(this->value));
};

// Código
void DoubleNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type DoubleNode::get_type() const { return Type::DOUBLE; };

// Construtores
DoubleNode::DoubleNode(int line, double value)
    : ExpressionNode(line), value(value) {};