#pragma once
#include "double.hpp"

struct BoolNode : public ExpressionNode {
  bool value;

  BoolNode(int line, bool value);
  void print(ostream& os) const override;
  Type get_type() const override;
  Value evaluate() override;
};