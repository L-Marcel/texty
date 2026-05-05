#pragma once
#include "long.hpp"

struct FloatNode : public ExpressionNode {
  float value;

  FloatNode(int line, float value);
  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};