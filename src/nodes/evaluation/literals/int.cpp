#include "int.hpp"

#include "../../../lib/magic_enum.hpp"

// Debug
void IntNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->get_type().kind)) +
                             ": " + to_string(this->value));
};

// Código
void IntNode::compile_code(ostream& os) const {
  os << "((int32_t)" << this->value << ")";
};

// Tipagem
Type IntNode::get_type() const { return Type(TypeKind::INT); };

// Construtores
IntNode::IntNode(int line, int32_t value)
    : ExpressionNode(line), value(value) {};
