#include "numeric.hpp"

const set<TypeKind> numeric_types = {TypeKind::BYTE, TypeKind::INT,
                                     TypeKind::LONG, TypeKind::FLOAT,
                                     TypeKind::DOUBLE};

const set<TypeKind> pointwise_types = {TypeKind::BYTE, TypeKind::INT,
                                       TypeKind::LONG, TypeKind::BOOL};

bool check_if_is_numeric(const Type& type) {
  return numeric_types.find(type.kind) != numeric_types.end();
};

bool check_if_is_pointwise(const Type& type) {
  return pointwise_types.find(type.kind) != pointwise_types.end();
};