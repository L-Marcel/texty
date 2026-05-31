#pragma once
#include "break.hpp"

struct ContinueNode : public Node {
  ContinueNode(int line);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};