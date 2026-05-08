#pragma once
#include "../compiler.hpp"

struct ExpressionNode : public Node {
  virtual ~ExpressionNode() = default;

 protected:
  ExpressionNode(int line);
  ExpressionNode(int line, string name);
};