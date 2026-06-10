#pragma once
#include "../variables/variable.hpp"

struct FunctionReference : public Reference {
  vector<Type> params;
  bool self;
  bool implemented;
  FunctionReference(Type node_type, vector<Type> params, bool self,
                    bool implemented);
};
