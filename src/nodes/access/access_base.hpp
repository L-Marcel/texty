#pragma once
#include "../evaluation/expression.hpp"

struct AccessBaseNode : public Node {
  AccessBaseType access_type;
  ExpressionNode* expression;

  AccessBaseNode(int line);
  AccessBaseNode(int line, string name);
  AccessBaseNode(int line, ExpressionNode* expression);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
  Reference* get_reference(int line) const;
};