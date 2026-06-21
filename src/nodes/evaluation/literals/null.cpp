#include "null.hpp"

// Debug
void NullNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "NULL");
};

// Código
void NullNode::compile_code(ostream& os) const { os << "NULL"; };

// Tipagem
Type NullNode::get_type() const {
  return this->expected_type;
};

void NullNode::set_expected_type(Type type) {
  this->expected_type = Type(type);
};

// Construtores
NullNode::NullNode(int line) : ExpressionNode(line, "null"),
      expected_type(Type(TypeKind::UNKNOWN)) {
        this->expected_type = Type(TypeKind::POINTER, new Type(TypeKind::UNKNOWN));
      };
