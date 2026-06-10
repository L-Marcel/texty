#pragma once
#include "node.hpp"

struct ProgramNode : public Node {
  ProgramNode(int line);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};