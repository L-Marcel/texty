#pragma once
#include "string.hpp"

struct CharNode : public ExpressionNode {
  char value;

  CharNode(int line, char value);
  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};