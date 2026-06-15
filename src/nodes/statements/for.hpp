#pragma once
#include "if.hpp"

struct ForNode : public Node {
  ForType type;
  ExpressionNode* expression;
  AttrNode* attr;
  ExpressionNode* condition;
  ExpressionNode* increment;

  ForNode(int line, string name, ExpressionNode* expression);
  ForNode(int line, AttrNode* attr, ExpressionNode* condition,
          ExpressionNode* increment);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
  ReturnCoverage get_return_coverage() const override;
};