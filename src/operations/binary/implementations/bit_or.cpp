#include "bit_or.hpp"

Type binary_bit_or_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_pointwise(left) && check_if_is_pointwise(right) &&
      left == right) {
    return left;
  } else {
    throw error("operação binária '|' não definida para os tipos (" +
                    left.to_string() + "," + right.to_string() + ")",
                line);
  };
};