#pragma once
#include "return.hpp"

struct IfEndNode : public Node {
  IfEndType type;
  AccessNode* access;
  string access_id;
  ExpressionNode* expression;
  IfEndNode* next;

  IfEndNode(int line, ExpressionNode* expression, IfEndNode* next);
  IfEndNode(int line, AccessNode* access, string access_id, IfEndNode* next);
  IfEndNode(int line, IfEndNode* next);
  IfEndNode(int line);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};