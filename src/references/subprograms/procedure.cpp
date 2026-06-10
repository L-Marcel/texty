#include "procedure.hpp"

// Construtores
ProcedureReference::ProcedureReference(vector<Type> params, bool self,
                                       bool implemented)
    : Reference(Type(TypeKind::VOID), ReferenceType::PROCEDURE),
      params(params),
      self(self),
      implemented(implemented) {};