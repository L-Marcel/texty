#pragma once
#include "context.hpp"

struct Compiler {
  static void add_dot_node(ostream& os, const Node* node, string label);
  static void add_dot_relation(ostream& os, const Node* from, Node* to);
  static void create_dot(Context& ctx, string filename);
  static void create_code(Context& ctx, string filename);
};