#pragma once
#include "subprogram.hpp"

struct FunctionNode : public SubprogramNode {
  Type type;

  FunctionNode(int line, string name, Type type,
               vector<pair<string, Type>> params);
  FunctionNode(int line, string name, Type type,
               vector<pair<string, Type>> params, bool self);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};
