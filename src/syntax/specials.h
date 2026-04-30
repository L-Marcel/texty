#pragma once
#include "tree.h"

struct IdNode : public Node {
  string name;

  IdNode(int line, string name);
  void print(ostream& os) const override;
  NodeType get_type() const override;
  void set_type(NodeType type);
};

struct PointerNode : public Node {
  Node* value;

  PointerNode(int line);
};

struct OptionNode : public Node {
  bool has_value;
  Node* value;

  OptionNode(int line);
};