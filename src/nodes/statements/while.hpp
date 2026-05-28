#pragma once
#include "for.hpp"

struct WhileNode : public Node {
  WhileType type;
  ExpressionNode* condition;

  WhileNode(int line, ExpressionNode* condition, WhileType type);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};