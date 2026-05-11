#include "bit_or.hpp"

Type binary_bit_or_get_type(const Type& left, const Type& right, int line) {
  if ((left == Type(TypeKind::BYTE) || left == Type(TypeKind::INT) || left == Type(TypeKind::LONG)) &&
      (right == Type(TypeKind::BYTE) || right == Type(TypeKind::INT) || right == Type(TypeKind::LONG)) &&
      left == right) {
    return left;
  } else {
    throw error("operação bitwise '|' não definida para os respectivos tipos", line);
  }
}