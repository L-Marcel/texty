#pragma once
#include "bool.hpp"

struct StringNode : public ExpressionNode {
  string value;

  StringNode(int line, string value);
  void print(ostream& os) const override;
  Type get_type() const override;
  Value evaluate() override;
};