#include "equals.hpp"

Type binary_eq_get_type(const Type& left, const Type& right, int line) {
  if (left == right) {
    return Type(TypeKind::BOOL);
  } else if (left.kind == TypeKind::POINTER && right.kind == TypeKind::POINTER) {
    if ((left.inner_type != nullptr && left.inner_type->kind == TypeKind::UNKNOWN) ||
        (right.inner_type != nullptr && right.inner_type->kind == TypeKind::UNKNOWN)) {
      return Type(TypeKind::BOOL);
    }
  }
  
  throw error("operação binária '==' não definida para os tipos (" +
                  left.to_string() + "," + right.to_string() + ")",
              line);
};

Type binary_not_eq_get_type(const Type& left, const Type& right, int line) {
  if (left == right) {
    return Type(TypeKind::BOOL);
  } else if (left.kind == TypeKind::POINTER && right.kind == TypeKind::POINTER) {
    if ((left.inner_type != nullptr && left.inner_type->kind == TypeKind::UNKNOWN) ||
        (right.inner_type != nullptr && right.inner_type->kind == TypeKind::UNKNOWN)) {
      return Type(TypeKind::BOOL);
    }
  }

  throw error("operação binária '!=' não definida para os tipos (" +
                  left.to_string() + "," + right.to_string() + ")",
              line);
};
