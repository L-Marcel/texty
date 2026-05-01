#include "bool.hpp"

// Debug
void BoolNode::print(ostream& os) const {
  Debug::print_node(os, this,
                    string(magic_enum::enum_name(this->get_type())) + ": " +
                        to_string(this->value));
};

// Tipagem
Type BoolNode::get_type() const { return Type::BOOL; };

// Avaliação
Value BoolNode::evaluate() { return Value(this->value); };

// Construtores
BoolNode::BoolNode(int line, bool value)
    : ExpressionNode(line), value(value) {};