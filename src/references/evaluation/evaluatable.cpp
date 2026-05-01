#include "evaluatable.hpp"

// Construtores
EvaluatableReference::EvaluatableReference(int offset, Type node_type,
                                           ReferenceType reference_type)
    : Reference(offset, node_type, reference_type) {};
