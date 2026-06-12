#include "mult.hpp"

Type binary_mult_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_numeric(left) && check_if_is_numeric(right) &&
      left == right) {
    return left;
  } else {
    throw error("operação binária '*' não definida para os tipos (" +
                    left.to_string() + "," + right.to_string() + ")",
                line);
  };
};

Type binary_div_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_numeric(left) && check_if_is_numeric(right) &&
      left == right) {
    return left;
  } else {
    throw error("operação binária '/' não definida para os tipos (" +
                    left.to_string() + "," + right.to_string() + ")",
                line);
  };
};

Type binary_mod_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_numeric(left) && check_if_is_numeric(right) &&
      left == right) {
    return left;
  } else {
    throw error("operação binária '%' não definida para os tipos (" +
                    left.to_string() + "," + right.to_string() + ")",
                line);
  };
};