#pragma once
#include "assign.hpp"

struct ReturnNode : public Node {
  ExpressionNode* expression;

  ReturnNode(int line, ExpressionNode* expression);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};