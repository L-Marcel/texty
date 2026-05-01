#pragma once
#include "../unary.hpp"

struct ByteNode : public ExpressionNode {
  uint8_t value;

  ByteNode(int line, uint8_t value);
  void print(ostream& os) const override;
  Type get_type() const override;
  Value evaluate() override;
};
