#include "numeric.hpp"

const set<Type> numeric_types = {Type::BYTE, Type::INT, Type::LONG, Type::FLOAT,
                                 Type::DOUBLE};

bool check_if_is_numeric(const Type& type) {
  return numeric_types.find(type) != numeric_types.end();
};