#pragma once
#include "../variables/variable.hpp"

struct FunctionReference : public Reference {
  vector<Type> params;
  FunctionReference(Type node_type, vector<Type> params);
};
