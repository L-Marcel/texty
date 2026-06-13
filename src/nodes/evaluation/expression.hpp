#pragma once
#include "../compiler.hpp"

struct ExpressionNode : public Node {
  virtual ~ExpressionNode() = default;
  virtual void set_expected_type(Type type);

 protected:
  ExpressionNode(int line);
  ExpressionNode(int line, string name);
};