#include "concat.hpp"

Type binary_array_concat_get_type(const Type& left, const Type& right,
                                  int line) {
  if (!check_if_is_array(left) || !check_if_is_array(right)) {
    throw error("operação não definida para os respectivos tipos", line);

  } else if (left.inner_type != right.inner_type) {
    throw error("não é possível concatenar arrays de tipos diferentes", line);
  }
  return left;
}
