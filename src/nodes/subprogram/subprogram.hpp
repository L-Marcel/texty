#pragma once
#include "../compiler.hpp"
#include "../evaluation/expression.hpp"

struct SubprogramNode : public Node {
  vector<pair<string, Type>> params;
  bool self;
  bool implemented;

  SubprogramNode(int line, string name, vector<pair<string, Type>> params,
                 bool self, bool implemented);

  virtual void compile_dot(ostream& os) const;
  virtual void compile_code(ostream& os) const;
  virtual Type get_type() const;

  virtual ~SubprogramNode() = default;
};

string params_to_string(vector<pair<string, Type>> params, bool production);
string params_ids_to_string(vector<pair<string, Type>> params, bool production);
string types_to_string(vector<Type> types, bool production);
string expressions_types_to_string(vector<ExpressionNode*> expressions,
                                   bool production);