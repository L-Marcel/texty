#pragma once
#include "expression.hpp"

struct BinaryOperationNode : public ExpressionNode {
  BinaryOperation operation;
  ExpressionNode* left;
  ExpressionNode* right;

  BinaryOperationNode(BinaryOperation operation, ExpressionNode* left,
                      ExpressionNode* right);

  void print(ostream& os) const override;
  Type get_type() const override;
  Value evaluate() override;
};