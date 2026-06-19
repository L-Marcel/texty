#pragma once
#include "case.hpp"

struct SwitchNode : public Node {
  ExpressionNode* expression;
  vector<CaseNode*> cases;

  SwitchNode(int line, ExpressionNode* expression, vector<CaseNode*> cases);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
  ReturnCoverage get_return_coverage() const override;
};