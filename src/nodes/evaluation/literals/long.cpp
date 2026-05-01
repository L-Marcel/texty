#include "long.hpp"

// Debug
void LongNode::print(ostream& os) const {
  Debug::print_node(os, this,
                    string(magic_enum::enum_name(this->get_type())) + ": " +
                        to_string(this->value));
};

// Tipagem
Type LongNode::get_type() const { return Type::LONG; };

// Avaliação
Value LongNode::evaluate() { return Value(this->value); };

// Construtores
LongNode::LongNode(int line, int64_t value)
    : ExpressionNode(line), value(value) {};