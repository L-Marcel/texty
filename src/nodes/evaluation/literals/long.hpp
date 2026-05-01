#pragma once
#include "int.hpp"

struct LongNode : public ExpressionNode {
  int64_t value;

  LongNode(int line, int64_t value);
  void print(ostream& os) const override;
  Type get_type() const override;
  Value evaluate() override;
};