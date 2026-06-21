#pragma once
#include "../expression.hpp"

struct NullNode : public ExpressionNode {
  Type expected_type;
  
  NullNode(int line);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
  void set_expected_type(Type type) override;
};
