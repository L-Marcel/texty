#include "function.hpp"

// Construtores
FunctionReference::FunctionReference(Type node_type, vector<Type> params,
                                     bool self, bool implemented)
    : Reference(node_type, ReferenceType::FUNCTION),
      params(params),
      self(self),
      implemented(implemented) {};