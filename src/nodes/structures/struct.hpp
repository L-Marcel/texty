#pragma once
#include "enum.hpp"

struct StructNode : public Node {
  vector<pair<string, Type>> attributes;

  StructNode(int line, string name, vector<pair<string, Type>> attributes);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};