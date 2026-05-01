#include "float.hpp"

// Debug
void FloatNode::print(ostream& os) const {
  Debug::print_node(os, this,
                    string(magic_enum::enum_name(this->get_type())) + ": " +
                        to_string(this->value));
};

// Tipagem
Type FloatNode::get_type() const { return Type::FLOAT; };

// Avaliação
Value FloatNode::evaluate() { return Value(this->value); };

// Construtores
FloatNode::FloatNode(int line, float value)
    : ExpressionNode(line), value(value) {};