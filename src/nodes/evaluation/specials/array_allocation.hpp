#pragma once
#include "range.hpp"

struct ArrayAllocationNode : public ExpressionNode {
  Type inner_type;
  ExpressionNode* size_expression;

  ArrayAllocationNode(int line, Type inner_type,
                      ExpressionNode* size_expression);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};