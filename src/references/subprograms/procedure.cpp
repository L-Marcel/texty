#include "procedure.hpp"

// Construtores
ProcedureReference::ProcedureReference(vector<Type> params)
    : Reference(Type(TypeKind::VOID), ReferenceType::PROCEDURE),
      params(params) {};