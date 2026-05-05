#pragma once
#include "int.hpp"

struct LongNode : public ExpressionNode {
  int64_t value;

  LongNode(int line, int64_t value);
  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};