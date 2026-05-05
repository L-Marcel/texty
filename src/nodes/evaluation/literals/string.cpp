#include "string.hpp"

// Debug
void StringNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->get_type())) +
                             ": \\\"" + this->value + "\\\"");
};

// Código
void StringNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type StringNode::get_type() const { return Type::STRING; };

// Construtores
StringNode::StringNode(int line, string value)
    : ExpressionNode(line), value(value) {};