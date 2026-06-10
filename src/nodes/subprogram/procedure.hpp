#pragma once
#include "function.hpp"

struct ProcedureNode : public SubprogramNode {
  ProcedureNode(int line, string name, vector<pair<string, Type>> params,
                bool self, bool implemented);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};