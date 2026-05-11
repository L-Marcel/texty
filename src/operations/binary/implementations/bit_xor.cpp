#include "bit_xor.hpp"

bool check_if_is_integral(const Type& type) {
  return type == Type(TypeKind::BYTE) || type == Type(TypeKind::INT) ||
         type == Type(TypeKind::LONG);
}

Type binary_xor_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_integral(left) && check_if_is_integral(right) &&
      left == right) {
    return left;
  }

  throw error("operação não definida para os respectivos tipos", line);
}