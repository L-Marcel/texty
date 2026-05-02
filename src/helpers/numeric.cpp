#include "numeric.hpp"

const set<Type> numeri_types = {Type::BYTE, Type::INT, Type::LONG, Type::FLOAT,
                                Type::DOUBLE};

bool check_if_is_numeric(const Type& type) {
  return numeri_types.find(type) != numeri_types.end();
};