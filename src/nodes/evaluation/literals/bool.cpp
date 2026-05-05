#include "bool.hpp"

// Debug
void BoolNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->get_type())) +
                             ": " + to_string(this->value));
};

// Código
void BoolNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type BoolNode::get_type() const { return Type::BOOL; };

// Construtores
BoolNode::BoolNode(int line, bool value)
    : ExpressionNode(line), value(value) {};