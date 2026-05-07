#include "numeric.hpp"

const set<Type> numeric_types = {TypeKind::BYTE, TypeKind::INT, TypeKind::LONG,
                                 TypeKind::FLOAT, TypeKind::DOUBLE};

bool check_if_is_numeric(const Type& type) {
  return numeric_types.find(type) != numeric_types.end();
};