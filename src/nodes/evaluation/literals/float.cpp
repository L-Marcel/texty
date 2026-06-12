#include "float.hpp"

// Debug
void FloatNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->get_type().kind)) +
                             ": " + to_string(this->value));
};

// Código
void FloatNode::compile_code(ostream& os) const {
  os << showpoint << this->value << "f";
};

// Tipagem
Type FloatNode::get_type() const { return Type(TypeKind::FLOAT); };

// Construtores
FloatNode::FloatNode(int line, float value)
    : ExpressionNode(line), value(value) {};