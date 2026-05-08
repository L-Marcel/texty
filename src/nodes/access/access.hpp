#pragma once
#include "access_base.hpp"

struct AccessNode : public ExpressionNode {
  AccessType access_type;
  AccessNode* previous;
  ExpressionNode* expression;
  AccessBaseNode* base;
  Node* call;  // TODO

  AccessNode(int line, AccessBaseNode* base);
  AccessNode(int line, Node* call);
  AccessNode(int line, string name, AccessNode* previous,
             AccessType access_type);
  AccessNode(int line, AccessNode* previous, ExpressionNode* expression);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};