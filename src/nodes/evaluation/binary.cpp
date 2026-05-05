#include "binary.hpp"

#include "../../operations/binary/binary.hpp"

// Debug
void BinaryOperationNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->operation)));
  if (this->left) Compiler::add_dot_relation(os, this, this->left);
  if (this->right) Compiler::add_dot_relation(os, this, this->right);
}

// Código
void BinaryOperationNode::compile_code(ostream& os) const {
  // TODO
}

// Tipagem
Type BinaryOperationNode::get_type() const {
  Type left = this->left->get_type();
  Type right = this->right->get_type();
  BinaryTypeCheckFunction result =
      BinaryOperations::get_type(this->operation, this->line);
  return result(left, right, this->line);
};

// Construtores
BinaryOperationNode::BinaryOperationNode(BinaryOperation operation,
                                         ExpressionNode* left,
                                         ExpressionNode* right)
    : ExpressionNode(left->line),
      operation(operation),
      left(left),
      right(right) {};