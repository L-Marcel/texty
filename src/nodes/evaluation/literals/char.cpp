#include "char.hpp"

// Debug
void CharNode::print(ostream& os) const {
  Debug::print_node(os, this,
                    string(magic_enum::enum_name(this->get_type())) + ": '" +
                        to_string(this->value) + "'");
};

// Tipagem
Type CharNode::get_type() const { return Type::CHAR; };

// Avaliação
Value CharNode::evaluate() { return Value(this->value); };

// Construtores
CharNode::CharNode(int line, char value)
    : ExpressionNode(line), value(value) {};