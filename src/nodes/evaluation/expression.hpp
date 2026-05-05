#pragma once
#include "../compiler.hpp"

struct ExpressionNode : Node {
  virtual ~ExpressionNode() = default;

 protected:
  ExpressionNode(int line);
};