#pragma once
#include "evaluatable.hpp"

struct VariableReference : public EvaluatableReference {
  Value value;

  VariableReference(int offset, Type node_type);
  Value evaluate() override;
};