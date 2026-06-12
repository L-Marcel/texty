#include "pointer.hpp"

bool check_if_is_pointer(const Type& type) {
  return type.kind == TypeKind::POINTER;
};