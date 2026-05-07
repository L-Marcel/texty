#include "long.hpp"

// Debug
void LongNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->get_type().kind)) +
                             ": " + to_string(this->value));
};

// Código
void LongNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type LongNode::get_type() const { return Type(TypeKind::LONG); };

// Construtores
LongNode::LongNode(int line, int64_t value)
    : ExpressionNode(line), value(value) {};