#include "relational.hpp"

const set<TypeKind> support_contains_type = {TypeKind::STRING, TypeKind::RANGE,
                                             TypeKind::ARRAY, TypeKind::OPTION};

bool check_if_support_contains(const Type& type) {
  return support_contains_type.find(type.kind) != support_contains_type.end();
};