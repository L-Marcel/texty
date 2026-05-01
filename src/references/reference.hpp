#pragma once
#include "value.hpp"

struct Reference {
  int offset;
  Type node_type;
  ReferenceType reference_type;

  virtual ~Reference() = default;

 protected:
  Reference(int offset, Type node_type, ReferenceType reference_type)
      : offset(offset), node_type(node_type), reference_type(reference_type) {};
};
