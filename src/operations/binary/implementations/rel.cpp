#include "rel.hpp"

Type binary_gt_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_numeric(left) && check_if_is_numeric(right) &&
      left == right) {
    return TypeKind::BOOL;
  } else {
    throw error("operação não definida para os respectivos tipos", line);
  }
}

Type binary_lt_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_numeric(left) && check_if_is_numeric(right) &&
      left == right) {
    return TypeKind::BOOL;
  } else {
    throw error("operação não definida para os respectivos tipos", line);
  }
}
Type binary_gt_eq_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_numeric(left) && check_if_is_numeric(right) &&
      left == right) {
    return TypeKind::BOOL;
  } else {
    throw error("operação não definida para os respectivos tipos", line);
  }
}
Type binary_lt_eq_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_numeric(left) && check_if_is_numeric(right) &&
      left == right) {
    return TypeKind::BOOL;
  } else {
    throw error("operação não definida para os respectivos tipos", line);
  }
}
Type binary_in_get_type(const Type& left, const Type& right, int line) {
  Type array_type = Type(TypeKind::ARRAY);
  if (right == array_type && left == *right.inner_type) {
    return TypeKind::BOOL;
  } else {
    throw error("operação não definida para os respectivos tipos", line);
  }
}
