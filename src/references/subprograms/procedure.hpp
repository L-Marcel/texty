#pragma once
#include "function.hpp"

struct ProcedureReference : public Reference {
  vector<Type> params;
  ProcedureReference(vector<Type> params);
};
