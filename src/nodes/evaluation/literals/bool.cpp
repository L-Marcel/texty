#include "bool.hpp"

// Debug
void BoolNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->get_type().kind)) +
                             ": " + to_string(this->value));
};

// Código
void BoolNode::compile_code(ostream& os) const {
  os << (this->value ? "((uint8_t)1)" : "((uint8_t)0)");
};

// Tipagem
Type BoolNode::get_type() const { return Type(TypeKind::BOOL); };

// Construtores
BoolNode::BoolNode(int line, bool value)
    : ExpressionNode(line), value(value) {};
