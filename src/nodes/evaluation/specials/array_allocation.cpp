#include "array_allocation.hpp"

// Debug
void ArrayAllocationNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(
      os, this,
      "new " +
          string(magic_enum::enum_name(this->get_type().inner_type->kind)) +
          "[]");
  Compiler::add_dot_relation(os, this, this->size_expression);
  for (size_t i = 0; i < this->children.size(); i++) {
    Compiler::add_dot_relation(os, this, this->children[i]);
  };
}

// Código
void ArrayAllocationNode::compile_code(ostream& os) const {
  // TODO
}

// Tipagem
Type ArrayAllocationNode::get_type() const {
  return Type(TypeKind::ARRAY, new Type(this->inner_type));
};

// Construtores
ArrayAllocationNode::ArrayAllocationNode(int line, Type inner_type,
                                         ExpressionNode* size_expression)
    : ExpressionNode(line),
      inner_type(inner_type),
      size_expression(size_expression) {};