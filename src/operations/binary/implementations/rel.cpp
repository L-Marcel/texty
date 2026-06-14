#include "rel.hpp"

Type binary_gt_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_numeric(left) && check_if_is_numeric(right) &&
      left == right) {
    return TypeKind::BOOL;
  } else {
    throw error("operação binária '>' não definida para os tipos (" +
                    left.to_string() + "," + right.to_string() + ")",
                line);
  };
};

Type binary_lt_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_numeric(left) && check_if_is_numeric(right) &&
      left == right) {
    return TypeKind::BOOL;
  } else {
    throw error("operação binária '<' não definida para os tipos (" +
                    left.to_string() + "," + right.to_string() + ")",
                line);
  };
};

Type binary_gt_eq_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_numeric(left) && check_if_is_numeric(right) &&
      left == right) {
    return TypeKind::BOOL;
  } else {
    throw error("operação binária '>=' não definida para os tipos (" +
                    left.to_string() + "," + right.to_string() + ")",
                line);
  };
};

Type binary_lt_eq_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_numeric(left) && check_if_is_numeric(right) &&
      left == right) {
    return TypeKind::BOOL;
  } else {
    throw error("operação binária '<=' não definida para os tipos (" +
                    left.to_string() + "," + right.to_string() + ")",
                line);
  };
};

Type binary_in_get_type(const Type& left, const Type& right, int line) {
  if (check_if_support_contains(right) &&
      (left.kind == right.inner_type->kind ||
       (left.kind == TypeKind::OPTION && left.kind == right.kind) ||
       (left.kind == TypeKind::STRING && left.kind == right.kind))) {
    return TypeKind::BOOL;
  } else {
    throw error("operação binária 'in' não definida para os tipos (" +
                    left.to_string() + "," + right.to_string() + ")",
                line);
  };
};
