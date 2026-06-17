#pragma once
#include "context.hpp"

extern stringstream generated_code;

struct Compiler {
  static void add_dot_node(ostream& os, const Node* node, string label);
  static void add_dot_node_item(ostream& os, const Node* node, string item);
  static void add_dot_node_item_relation(ostream& os, const Node* node,
                                         string item, const Node* to);
  static void add_dot_relation(ostream& os, const Node* from, const Node* to);
  static void create_dot(Context& ctx, string filename);
  static void create_code(Context& ctx, string filename);
};