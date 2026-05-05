#include "float.hpp"

// Debug
void FloatNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->get_type())) +
                             ": " + to_string(this->value));
};

// Código
void FloatNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type FloatNode::get_type() const { return Type::FLOAT; };

// Construtores
FloatNode::FloatNode(int line, float value)
    : ExpressionNode(line), value(value) {};