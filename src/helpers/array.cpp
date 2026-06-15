#include "array.hpp"

bool check_if_is_array(const Type& type) {
  return type.kind == TypeKind::ARRAY;
};