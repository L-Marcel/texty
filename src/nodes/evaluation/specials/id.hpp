#pragma once
#include "option.hpp"

struct IdNode : public ExpressionNode {
  string name;

  IdNode(int line, string name);
  void print(ostream& os) const override;
  Reference* get_reference() const;
  Value evaluate() override;
};