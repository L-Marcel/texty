#include "unary.hpp"

Type unary_minus_get_type(const Type& node, int line) {
  if (check_if_is_numeric(node)) {
    return node;
  } else {
    throw error("operação unária '-' não definida para o tipo", line);
  }
}

Type unary_not_get_type(const Type& node, int line) {
  if (node == Type(TypeKind::BOOL)) {
    return node;
  } else {
    throw error("operação unária '!' não definida para o tipo", line);
  }
}

Type unary_rev_get_type(const Type& node, int line) {
  if (node == Type(TypeKind::BYTE) || node == Type(TypeKind::INT) || node == Type(TypeKind::LONG)) {
    return node;
  } else {
    throw error("operação unária '~' não definida para o tipo", line);
  }
}

Type unary_ref_get_type(const Type& node, int line) {
  return Type(TypeKind::POINTER, new Type(node));
}
