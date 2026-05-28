#pragma once
#include "while.hpp"

struct CaseNode : public Node {
  CaseType type;
  vector<ExpressionNode*> expressions;

  CaseNode(int line, vector<ExpressionNode*> expressions);
  CaseNode(int line);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};