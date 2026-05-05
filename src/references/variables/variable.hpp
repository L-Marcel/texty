#pragma once
#include "../reference.hpp"

struct VariableReference : public Reference {
  Value value;

  VariableReference(int offset, Type node_type);
};