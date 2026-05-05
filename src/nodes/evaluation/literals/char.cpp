#include "char.hpp"

// Debug
void CharNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->get_type())) +
                             ": '" + to_string(this->value) + "'");
};

// Código
void CharNode::compile_code(ostream& os) const {

};

// Tipagem
Type CharNode::get_type() const { return Type::CHAR; };

// Construtores
CharNode::CharNode(int line, char value)
    : ExpressionNode(line), value(value) {};