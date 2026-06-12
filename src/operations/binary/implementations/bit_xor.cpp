#include "bit_xor.hpp"

Type binary_xor_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_pointwise(left) && check_if_is_pointwise(right) &&
      left == right) {
    return left;
  } else {
    throw error("operação binária '^' não definida para os tipos (" +
                    left.to_string() + "," + right.to_string() + ")",
                line);
  };
};