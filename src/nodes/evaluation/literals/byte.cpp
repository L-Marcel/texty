#include "byte.hpp"

// Debug
void ByteNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->get_type().kind)) +
                             ": " + to_string(this->value));
};

// Código
void ByteNode::compile_code(ostream& os) const {
  os << "((uint8_t)" << static_cast<unsigned int>(this->value)
     << "U)";
};

// Tipagem
Type ByteNode::get_type() const { return Type(TypeKind::BYTE); };

// Construtores
ByteNode::ByteNode(int line, uint8_t value)
    : ExpressionNode(line), value(value) {};