#pragma once
#include "string.hpp"

struct CharNode : public ExpressionNode {
  char value;

  CharNode(int line, char value);
  void print(ostream& os) const override;
  Type get_type() const override;
  Value evaluate() override;
};