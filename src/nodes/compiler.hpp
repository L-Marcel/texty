#pragma once

#include <sstream>

#include "context.hpp"

extern stringstream generated_implementations;
extern stringstream generated_declarations;
extern stringstream generated_type_implementations;

struct Compiler {
  static set<string> defined_arrays;
  static set<string> defined_options;
  static int label_counter;
  static string get_next_label(const string& prefix);

  static void register_array(Type inner_type);
  static void register_option(Type inner_type);

  static void add_dot_node(ostream& os, const Node* node, string label);
  static void add_dot_node_item(ostream& os, const Node* node, string item);
  static void add_dot_node_item_relation(ostream& os, const Node* node,
                                         string item, const Node* to);
  static void add_dot_relation(ostream& os, const Node* from, const Node* to);
  static void create_dot(Context& ctx, string filename);
  static void create_code(Context& ctx, string filename);
};