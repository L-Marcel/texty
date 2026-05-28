#pragma once
#include "../compiler.hpp"

struct FunctionNode : public Node {
  Type type;
  vector<pair<string, Type>> params;

  FunctionNode(int line, string name, Type type,
               vector<pair<string, Type>> params);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};

string params_to_string(vector<pair<string, Type>> params);