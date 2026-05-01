#pragma once
#include "binary.hpp"

struct UnaryOperationNode : public ExpressionNode {
  UnaryOperation operation;
  bool postfix = false;
  ExpressionNode* node;

  UnaryOperationNode(UnaryOperation operation, ExpressionNode* node);
  UnaryOperationNode(bool postfix, UnaryOperation operation,
                     ExpressionNode* node);

  void print(ostream& os) const override;
  Type get_type() const override;
  Value evaluate() override;
};