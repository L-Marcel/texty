#include "variable.hpp"

// Construtores
VariableReference::VariableReference(Type node_type, bool is_const)
    : Reference(node_type, ReferenceType::VARIABLE), is_const(is_const) {};
