#pragma once
#include "../unary.hpp"

struct OptionNode : public ExpressionNode {
  Option value;

  OptionNode(int line);
  Value evaluate() override;
};