#pragma once
#include "access_base.hpp"

struct SubprogramCallNode;

struct AccessNode : public ExpressionNode {
  AccessType access_type;
  AccessNode* previous;
  ExpressionNode* expression;
  AccessBaseNode* base;
  SubprogramCallNode* call;

  AccessNode(int line, AccessBaseNode* base);
  AccessNode(int line, SubprogramCallNode* call);
  AccessNode(int line, string name, AccessNode* previous,
             AccessType access_type);
  AccessNode(int line, AccessNode* previous, ExpressionNode* expression);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
  Reference* get_reference(int line) const;
  string to_string() const;
};