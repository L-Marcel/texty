#include "binary.hpp"

#include "../../operations/binary/binary.hpp"

// Debug
void BinaryOperationNode::print(ostream& os) const {
  Debug::print_node(os, this, string(magic_enum::enum_name(this->operation)));
  if (this->left) Debug::print_relation(os, this, this->left);
  if (this->right) Debug::print_relation(os, this, this->right);
}

// Tipagem
Type BinaryOperationNode::get_type() const {
  Type left = this->left->get_type();
  Type right = this->right->get_type();
  BinaryTypeCheckFunction result =
      BinaryOperations::get_type(this->operation, this->line);
  return result(left, right, this->line);
};

// Avaliação
Value BinaryOperationNode::evaluate() {
  Value left = this->left->evaluate();
  Value right = this->right->evaluate();
  BinaryEvaluationFunction result =
      BinaryOperations::get_function(this->operation, this->line);
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