#pragma once
#include "return.hpp"

struct IfEndNode : public Node {
  IfEndType type;
  string variable_id;
  ExpressionNode* expression;
  IfEndNode* next;

  IfEndNode(int line, ExpressionNode* expression, IfEndNode* next);
  IfEndNode(int line, ExpressionNode* expression, string variable_id,
            IfEndNode* next);
  IfEndNode(int line, IfEndNode* next);
  IfEndNode(int line);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  void compile_chain(ostream& os, const string& end_label) const;
  Type get_type() const override;
  ReturnCoverage get_return_coverage() const override;
};