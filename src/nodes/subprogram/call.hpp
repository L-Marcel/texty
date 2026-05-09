#pragma once
#include "../access/access.hpp"
#include "../evaluation/expression.hpp"
#include "procedure.hpp"

struct SubprogramCallNode : public Node {
  CallType call_type;
  AccessNode* access;
  vector<ExpressionNode*> params;
  Type target_type;

  SubprogramCallNode(int line, AccessNode* access,
                     vector<ExpressionNode*> params);
  SubprogramCallNode(int line, Type target_type,
                     vector<ExpressionNode*> params);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};