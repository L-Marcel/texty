#pragma once
#include "expression.hpp"

struct BinaryOperationNode : public ExpressionNode {
  BinaryOperation operation;
  ExpressionNode* left;
  ExpressionNode* right;

  BinaryOperationNode(BinaryOperation operation, ExpressionNode* left,
                      ExpressionNode* right);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};