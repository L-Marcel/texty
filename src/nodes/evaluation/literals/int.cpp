#include "int.hpp"

// Debug
void IntNode::print(ostream& os) const {
  Debug::print_node(os, this,
                    string(magic_enum::enum_name(this->get_type())) + ": " +
                        to_string(this->value));
};

// Tipagem
Type IntNode::get_type() const { return Type::INT; };

// Avaliação
Value IntNode::evaluate() { return Value(this->value); };

// Construtores
IntNode::IntNode(int line, int32_t value)
    : ExpressionNode(line), value(value) {};