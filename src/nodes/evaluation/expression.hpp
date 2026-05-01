#pragma once
#include "../context.hpp"

struct ExpressionNode : Node {
  virtual Value evaluate() = 0;
  virtual ~ExpressionNode() = default;

 protected:
  ExpressionNode(int line);
};