#pragma once
#include "if_end.hpp"

struct IfNode : public Node {
  IfType type;
  ExpressionNode* expression;
  string variable_id;
  IfEndNode* next;

  IfNode(int line, ExpressionNode* expression, IfEndNode* next);
  IfNode(int line, ExpressionNode* expression, string variable_id,
         IfEndNode* next);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};