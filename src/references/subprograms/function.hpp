#pragma once
#include "../variables/variable.hpp"

// TODO: Isso aqui precisa de cabeçalho
// TODO: Isso aqui precisa ser chamável
// INFO: O node_type é o tipo do retorno

struct FunctionReference : public Reference {
  FunctionReference(int offset, Type node_type);
};
