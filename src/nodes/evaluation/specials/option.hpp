#pragma once
#include "../unary.hpp"

struct OptionNode : public ExpressionNode {
  Option value;

  OptionNode(int line, Option value);
  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};