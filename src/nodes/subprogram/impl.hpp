#pragma once
#include "trait.hpp"

struct ImplNode : public Node {
  string target;
  vector<SubprogramNode*> subprograms;

  ImplNode(int line, string name, vector<SubprogramNode*> subprograms);
  ImplNode(int line, string name, string target,
           vector<SubprogramNode*> subprograms);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};