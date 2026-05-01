#include "binary.hpp"

// Debug
void BinaryOperationNode::print(ostream& os) const {
  Debug::print_node(os, this, string(magic_enum::enum_name(this->operation)));
  if (this->left) Debug::print_relation(os, this, this->left);
  if (this->right) Debug::print_relation(os, this, this->right);
}

// Tipagem
Type BinaryOperationNode::get_type() const { return this->left->get_type(); };

// Construtores
BinaryOperationNode::BinaryOperationNode(BinaryOperation operation,
                                         ExpressionNode* left,
                                         ExpressionNode* right)
    : ExpressionNode(left->line),
      operation(operation),
      left(left),
      right(right) {};