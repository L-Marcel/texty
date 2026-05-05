#pragma once
#include "option.hpp"

struct IdNode : public ExpressionNode {
  string name;

  IdNode(int line, string name);
  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Reference* get_reference() const;
};