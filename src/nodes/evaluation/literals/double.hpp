#pragma once
#include "float.hpp"

struct DoubleNode : public ExpressionNode {
  double value;

  DoubleNode(int line, double value);
  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};