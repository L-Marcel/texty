#include "string.hpp"

// Debug
void StringNode::print(ostream& os) const {
  Debug::print_node(os, this,
                    string(magic_enum::enum_name(this->get_type())) + ": \\\"" +
                        this->value + "\\\"");
};

// Tipagem
Type StringNode::get_type() const { return Type::STRING; };

// Avaliação
Value StringNode::evaluate() { return Value(this->value); };

// Construtores
StringNode::StringNode(int line, string value)
    : ExpressionNode(line), value(value) {};