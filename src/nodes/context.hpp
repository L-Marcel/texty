#pragma once
#include "debug.hpp"

struct Context {
  int line = 1;
  Node* root;
  bool has_lexical_error = false;

  Context() = default;
  ~Context() = default;
};