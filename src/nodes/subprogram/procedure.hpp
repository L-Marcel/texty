#pragma once
#include "function.hpp"

struct ProcedureNode : public Node {
  vector<pair<string, Type>> params;

  ProcedureNode(int line, string name, vector<pair<string, Type>> params);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};