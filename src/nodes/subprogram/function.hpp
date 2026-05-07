#pragma once
#include "../compiler.hpp"

typedef pair<string, Type> Param;

struct FunctionNode : public Node {
  Type type;
  vector<Param> params;

  FunctionNode(int line, string name, Type type, vector<Param> params);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};

string params_to_string(vector<Param> params);