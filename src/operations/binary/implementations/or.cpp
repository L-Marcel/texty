#include "or.hpp"

Type binary_or_get_type(const Type& left, const Type& right, int line) {
  Type bool_type = Type(TypeKind::BOOL);
  if (left == bool_type && right == bool_type) {
    return bool_type;
  } else {
    throw error("operação binária '||' não definida para os tipos (" +
                    left.to_string() + "," + right.to_string() + ")",
                line);
  };
};