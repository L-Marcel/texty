#include "sum.hpp"

Type binary_plus_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_numeric(left) && check_if_is_numeric(right) &&
      left == right) {
    return left;
  } else {
    throw error("operação não definida para os respectivos tipos", line);
  }
};

Type binary_minus_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_numeric(left) && check_if_is_numeric(right) &&
      left == right) {
    return left;
  } else {
    throw error("operação não definida para os respectivos tipos", line);
  }
};