#include "variable.hpp"

// Avaliações
Value VariableReference::evaluate() { return this->value; };

// Construtores
VariableReference::VariableReference(int offset, Type node_type)
    : EvaluatableReference(offset, node_type, ReferenceType::VARIABLE) {};
