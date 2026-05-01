#pragma once
#include "../reference.hpp"

struct EvaluatableReference : public Reference {
  Value value;

  virtual ~EvaluatableReference() = default;
  virtual Value evaluate() = 0;

 protected:
  EvaluatableReference(int offset, Type node_type,
                       ReferenceType reference_type);
};