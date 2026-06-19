#pragma once
#include "../references/reference.hpp"

struct Node {
  vector<Node*> children;
  string name;
  int line;

  virtual void compile_dot(ostream& os) const;
  virtual void compile_code(ostream& os) const;
  virtual Type get_type() const;
  virtual ReturnCoverage get_return_coverage() const;
  virtual ~Node() = default;

  Node(int line);
  Node(int line, string name);
};