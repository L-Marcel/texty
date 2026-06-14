#include "unary.hpp"

Type unary_minus_get_type(const Type& node, int line) {
  if (check_if_is_numeric(node)) {
    return node;
  } else {
    throw error("operação unária '-' não definida para o tipo (" +
                    node.to_string() + ")",
                line);
  }
}

Type unary_not_get_type(const Type& node, int line) {
  if (node == Type(TypeKind::BOOL)) {
    return node;
  } else {
    throw error("operação unária '!' não definida para o tipo (" +
                    node.to_string() + ")",
                line);
  }
}

Type unary_rev_get_type(const Type& node, int line) {
  if (node == Type(TypeKind::BYTE) || node == Type(TypeKind::INT) ||
      node == Type(TypeKind::LONG)) {
    return node;
  } else {
    throw error("operação unária '~' não definida para o tipo (" +
                    node.to_string() + ")",
                line);
  }
}

Type unary_ref_get_type(const Type& node, int line) {
  if (node == Type(TypeKind::VOID)) {
    throw error("operação unária '&' não definida para o tipo (" +
                    node.to_string() + ")",
                line);
  };

  return Type(TypeKind::POINTER, new Type(node));
}

Type unary_deref_get_type(const Type& node, int line) {
  if (check_if_is_pointer(node) && node.inner_type != nullptr) {
    return *node.inner_type;
  } else {
    throw error("operação unária '*' não definida para o tipo (" +
                    node.to_string() + ")",
                line);
  }
}

Type unary_increment_get_type(const Type& node, int line) {
  if (check_if_is_numeric(node)) {
    return node;
  } else {
    throw error("operação unária '++' não definida para o tipo (" +
                    node.to_string() + ")",
                line);
  }
}

Type unary_decrement_get_type(const Type& node, int line) {
  if (check_if_is_numeric(node)) {
    return node;
  } else {
    throw error("operação unária '--' não definida para o tipo (" +
                    node.to_string() + ")",
                line);
  }
}
