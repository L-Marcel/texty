#pragma once
#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <string_view>

#include "../src/syntax/tree.h"
#include "magic_enum.hpp"

using namespace std;

struct Debug {
  static void print_node(ostream& os, const Node* node, string label);
  static void print_relation(ostream& os, const Node* from, Node* to);
};