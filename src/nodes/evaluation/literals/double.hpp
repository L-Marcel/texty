#pragma once
#include "float.hpp"

struct DoubleNode : public ExpressionNode {
  double value;

  DoubleNode(int line, double value);
  void print(ostream& os) const override;
  Type get_type() const override;
  Value evaluate() override;
};