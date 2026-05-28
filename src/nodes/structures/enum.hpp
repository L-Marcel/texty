#pragma once
#include "../statements/switch.hpp"

struct EnumNode : public Node {
  vector<string> values;

  EnumNode(int line, string name, vector<string> values);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};