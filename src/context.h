#pragma once
#include "syntax/tree.h"

struct Context {
  int line = 1;
  Node* root;

  Context() = default;
  ~Context() = default;
};