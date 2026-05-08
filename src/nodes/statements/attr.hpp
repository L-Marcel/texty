#pragma once
#include "../evaluation/expression.hpp"

struct AttrNode : public Node {
  bool is_const;
  Type type;
  ExpressionNode* expression;

  AttrNode(int line, string name, bool is_const, Type type,
           ExpressionNode* expression);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};