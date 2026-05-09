#pragma once
#include "id.hpp"

struct RangeNode : public ExpressionNode {
  ExpressionNode* left;
  RangeInclusionType left_inclusion;
  ExpressionNode* right;
  RangeInclusionType right_inclusion;

  RangeNode(int line, bool left, ExpressionNode* expression,
            RangeInclusionType expression_inclusion);
  RangeNode(int line, ExpressionNode* left, RangeInclusionType left_inclusion,
            ExpressionNode* right, RangeInclusionType right_inclusion);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};