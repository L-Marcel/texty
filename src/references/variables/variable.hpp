#pragma once
#include "../reference.hpp"

struct VariableReference : public Reference {
  bool is_const;

  VariableReference(Type node_type, bool is_const);
};