#include "numeric.hpp"

const set<Type> numeric_types = {TypeKind::BYTE, TypeKind::INT, TypeKind::LONG,
                                 TypeKind::FLOAT, TypeKind::DOUBLE};

const set<Type> pointwise_types = {TypeKind::BYTE, TypeKind::INT,
                                   TypeKind::LONG, TypeKind::BOOL};

bool check_if_is_numeric(const Type& type) {
  return numeric_types.find(type) != numeric_types.end();
};

bool check_if_is_pointwise(const Type& type) {
  return pointwise_types.find(type) != pointwise_types.end();
};