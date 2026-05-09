#pragma once
#include "value.hpp"

struct Reference {
  Type node_type;
  ReferenceType reference_type;

  virtual ~Reference() = default;

  Reference(Type node_type, ReferenceType reference_type)
      : node_type(node_type), reference_type(reference_type) {};
};
