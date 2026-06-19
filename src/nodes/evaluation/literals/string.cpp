#include "string.hpp"

#include "../../../lib/magic_enum.hpp"

// Debug
void StringNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->get_type().kind)) +
                             ": \\\"" + this->value + "\\\"");
};

// Código
void StringNode::compile_code(ostream& os) const {
  os << "(char*)(\"" << this->value << "\")";
};

// Tipagem
Type StringNode::get_type() const { return Type(TypeKind::STRING); };

// Construtores
StringNode::StringNode(int line, string value)
    : ExpressionNode(line), value(value) {};
