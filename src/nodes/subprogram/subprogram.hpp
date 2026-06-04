#pragma once
#include "../compiler.hpp"

struct SubprogramNode : public Node {
  vector<pair<string, Type>> params;
  bool self;

  SubprogramNode(int line, string name, vector<pair<string, Type>> params);
  SubprogramNode(int line, string name, vector<pair<string, Type>> params,
                 bool self);

  virtual void compile_dot(ostream& os) const;
  virtual void compile_code(ostream& os) const;
  virtual Type get_type() const;

  virtual ~SubprogramNode() = default;
};

string params_to_string(vector<pair<string, Type>> params);