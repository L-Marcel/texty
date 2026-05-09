#include "or.hpp"

Type binary_or_get_type(const Type& left, const Type& right, int line) {
  Type bool_type = Type(TypeKind::BOOL);

  if (left == bool_type && right == bool_type) {
    return bool_type;
  }

  throw error("operação não definida para os respectivos tipos", line);
}