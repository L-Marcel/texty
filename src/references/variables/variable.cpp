#include "variable.hpp"

// Construtores
VariableReference::VariableReference(int offset, Type node_type)
    : Reference(offset, node_type, ReferenceType::VARIABLE) {};
