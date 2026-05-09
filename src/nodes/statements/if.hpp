#pragma once
#include "if_end.hpp"

struct IfNode : public Node {
  IfType type;
  AccessNode* access;
  string access_id;
  ExpressionNode* expression;
  IfEndNode* next;

  IfNode(int line, ExpressionNode* expression, IfEndNode* next);
  IfNode(int line, AccessNode* access, string access_id, IfEndNode* next);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};