#pragma once
#include "procedure.hpp"

struct TraitNode : public Node {
  vector<SubprogramNode*> subprograms;

  TraitNode(int line, string name, vector<SubprogramNode*> subprograms);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};