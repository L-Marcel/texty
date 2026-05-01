#include "byte.hpp"

// Debug
void ByteNode::print(ostream& os) const {
  Debug::print_node(os, this,
                    string(magic_enum::enum_name(this->get_type())) + ": " +
                        to_string(this->value));
};

// Tipagem
Type ByteNode::get_type() const { return Type::BYTE; };

// Avaliação
Value ByteNode::evaluate() { return Value(this->value); };

// Construtores
ByteNode::ByteNode(int line, uint8_t value)
    : ExpressionNode(line), value(value) {};