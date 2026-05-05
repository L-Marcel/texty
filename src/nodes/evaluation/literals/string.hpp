#pragma once
#include "bool.hpp"

struct StringNode : public ExpressionNode {
  string value;

  StringNode(int line, string value);
  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};