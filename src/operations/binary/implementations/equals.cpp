#include "equals.hpp"

Type binary_eq_get_type(const Type& left, const Type& right, int line) {
  if (left == right) {
    return TypeKind::BOOL;
  } else {
    throw error("operação não definida para os respectivos tipos", line);
  }
}
Type binary_not_eq_get_type(const Type& left, const Type& right, int line) {
  if (left == right) {
    return TypeKind::BOOL;
  } else {
    throw error("operação não definida para os respectivos tipos", line);
  }
}
