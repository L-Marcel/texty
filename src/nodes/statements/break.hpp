#pragma once
#include "switch.hpp"

struct BreakNode : public Node {
  BreakNode(int line);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};