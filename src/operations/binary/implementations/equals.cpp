#include "equals.hpp"

Type binary_eq_get_type(const Type& left, const Type& right, int line) {
  if (left == right) {
    return TypeKind::BOOL;
  } else {
    throw error("operação binária '==' não definida para os tipos (" +
                    left.to_string() + "," + right.to_string() + ")",
                line);
  };
};

Type binary_not_eq_get_type(const Type& left, const Type& right, int line) {
  if (left == right) {
    return TypeKind::BOOL;
  } else {
    throw error("operação binária '!=' não definida para os tipos (" +
                    left.to_string() + "," + right.to_string() + ")",
                line);
  };
};
