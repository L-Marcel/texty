#pragma once
#include "../evaluation/variable.hpp"

struct FunctionReference : public Reference {
  FunctionReference(int offset, Type node_type);
};
