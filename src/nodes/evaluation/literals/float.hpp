#pragma once
#include "long.hpp"

struct FloatNode : public ExpressionNode {
  float value;

  FloatNode(int line, float value);
  void print(ostream& os) const override;
  Type get_type() const override;
  Value evaluate() override;
};