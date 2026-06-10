#pragma once
#include "function.hpp"

struct ProcedureReference : public Reference {
  vector<Type> params;
  bool self;
  bool implemented;
  ProcedureReference(vector<Type> params, bool self, bool implemented);
};
