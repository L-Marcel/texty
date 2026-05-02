#pragma once
#include "function.hpp"

// TODO: Isso aqui precisa de cabeçalho
// TODO: Isso aqui precisa ser chamável

struct ProcedureReference : public Reference {
  ProcedureReference(int offset);
};
