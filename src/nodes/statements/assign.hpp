#pragma once
#include "../access/access.hpp"
#include "attr.hpp"

struct AssignNode : public Node {
  AssignType assign_type;
  BinaryOperation operation;
  AccessNode* access;
  ExpressionNode* expression;

  AssignNode(int line, AccessNode* access, ExpressionNode* expression);
  AssignNode(int line, BinaryOperation operation, AccessNode* access,
             ExpressionNode* expression);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};