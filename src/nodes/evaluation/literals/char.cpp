#include "char.hpp"

// Debug
void CharNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->get_type().kind)) +
                             ": '" + to_string(this->value) + "'");
};

// Código
void CharNode::compile_code(ostream& os) const {
  os << "'" << this->value << "'";
};

// Tipagem
Type CharNode::get_type() const { return Type(TypeKind::CHAR); };

// Construtores
CharNode::CharNode(int line, char value)
    : ExpressionNode(line), value(value) {};