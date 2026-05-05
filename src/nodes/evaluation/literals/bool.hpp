#pragma once
#include "double.hpp"

struct BoolNode : public ExpressionNode {
  bool value;

  BoolNode(int line, bool value);
  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};