#pragma once
#include "byte.hpp"

struct IntNode : public ExpressionNode {
  int32_t value;

  IntNode(int line, int32_t value);
  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};