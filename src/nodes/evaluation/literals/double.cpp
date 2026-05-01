#include "double.hpp"

// Debug
void DoubleNode::print(ostream& os) const {
  Debug::print_node(os, this,
                    string(magic_enum::enum_name(this->get_type())) + ": " +
                        to_string(this->value));
};

// Tipagem
Type DoubleNode::get_type() const { return Type::DOUBLE; };

// Avaliação
Value DoubleNode::evaluate() { return Value(this->value); };

// Construtores
DoubleNode::DoubleNode(int line, double value)
    : ExpressionNode(line), value(value) {};