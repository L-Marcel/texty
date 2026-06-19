#include "concat.hpp"

Type binary_array_concat_get_type(const Type& left, const Type& right,
                                  int line) {
  if (left.kind == TypeKind::STRING && right.kind == TypeKind::STRING) {
    return left;
  };

  if (check_if_is_array(left) && check_if_is_array(right) &&
      *left.inner_type == *right.inner_type) {
    return left;
  } else {
    throw error("operação binária '<<' não definida para os tipos (" +
                    left.to_string() + "," + right.to_string() + ")",
                line);
  };
};
