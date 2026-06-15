#pragma once
#include "assign.hpp"

struct ReturnNode : public Node {
  ReturnNodeType type;
  ExpressionNode* expression;
  Type expected_type;

  ReturnNode(int line);
  ReturnNode(int line, ExpressionNode* expression);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};