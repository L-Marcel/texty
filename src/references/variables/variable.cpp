#include "variable.hpp"

// Construtores
VariableReference::VariableReference(Type node_type, bool is_const, string name_suffix)
    : Reference(node_type, ReferenceType::VARIABLE), is_const(is_const), name_suffix(name_suffix) {};
