#pragma once
#include "../unary.hpp"

struct OptionNode : public ExpressionNode {
  OptionNodeType type;
  ExpressionNode* value;
  Type expected_type;

  OptionNode(int line);
  OptionNode(int line, ExpressionNode* value);
  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
  void set_expected_type(Type type);
};