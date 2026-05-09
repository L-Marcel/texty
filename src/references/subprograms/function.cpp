#include "function.hpp"

// Construtores
FunctionReference::FunctionReference(Type node_type, vector<Type> params)
    : Reference(node_type, ReferenceType::FUNCTION), params(params) {};