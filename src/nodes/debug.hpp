#pragma once
#include "node.hpp"

struct Debug {
  static void print_node(ostream& os, const Node* node, string label);
  static void print_relation(ostream& os, const Node* from, Node* to);
};