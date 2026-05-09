#include "value.hpp"

// Operadores
bool Type::operator==(const Type& a) const {
  if (this->kind != a.kind) return false;
  if (this->inner_type == nullptr && a.inner_type == nullptr) return true;
  if (this->inner_type != nullptr && a.inner_type != nullptr) {
    return *this->inner_type == *a.inner_type;
  }
  return false;
};
bool Type::operator!=(const Type& a) const { return !(*this == a); };
bool Type::operator<(const Type& a) const {
  if (this->kind != a.kind) return this->kind < a.kind;
  if (this->inner_type && a.inner_type) return *inner_type < *a.inner_type;
  return this->inner_type == nullptr && a.inner_type != nullptr;
};

// String
string Type::to_string() {
  if (kind == TypeKind::ARRAY) {
    return (inner_type ? inner_type->to_string() : "unknown") + "[]";
  } else if (kind == TypeKind::POINTER) {
    return "pointer<" + (inner_type ? inner_type->to_string() : "unknown") +
           ">";
  } else if (kind == TypeKind::OPTION) {
    return "option<" + (inner_type ? inner_type->to_string() : "unknown") + ">";
  };

  string name = string(magic_enum::enum_name(kind));
  transform(name.begin(), name.end(), name.begin(), ::tolower);

  return name;
};

// Construtores
Type::Type(TypeKind kind) : kind(kind), inner_type(nullptr) {};
Type::Type(TypeKind kind, Type* inner) : kind(kind), inner_type(inner) {};