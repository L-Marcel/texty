#include "value.hpp"

// Operadores
bool Type::operator==(const Type& a) const {
  if (this->kind != a.kind) return false;
  if (this->kind == TypeKind::NAMED) return this->name == a.name;
  if (this->inner_type == nullptr && a.inner_type == nullptr) return true;
  if (this->inner_type != nullptr && a.inner_type != nullptr) {
    return *this->inner_type == *a.inner_type;
  }
  return false;
};
bool Type::operator!=(const Type& a) const { return !(*this == a); };
bool Type::operator<(const Type& a) const {
  if (this->kind != a.kind) return this->kind < a.kind;
  if (this->kind == TypeKind::NAMED) return this->name < a.name;
  if (this->inner_type && a.inner_type) return *inner_type < *a.inner_type;
  return this->inner_type == nullptr && a.inner_type != nullptr;
};

// String
string Type::to_string() const {
  if (this->kind == TypeKind::NAMED)
    return this->name;
  else if (this->kind == TypeKind::ARRAY) {
    return (this->inner_type ? this->inner_type->to_string() : "unknown") +
           "[]";
  } else if (this->kind == TypeKind::POINTER) {
    return "pointer<" +
           (this->inner_type ? this->inner_type->to_string() : "unknown") + ">";
  } else if (this->kind == TypeKind::OPTION) {
    return "option<" +
           (this->inner_type ? this->inner_type->to_string() : "unknown") + ">";
  };

  string name = string(magic_enum::enum_name(this->kind));
  transform(name.begin(), name.end(), name.begin(), ::tolower);

  return name;
};

string Type::to_production() const {
  if (this->kind == TypeKind::NAMED)
    return this->name;
  else if (this->kind == TypeKind::ARRAY) {
    return "::txy::array<" +
           (this->inner_type ? this->inner_type->to_production() : "unknown") +
           ">";
  } else if (this->kind == TypeKind::POINTER) {
    return (this->inner_type ? this->inner_type->to_production() : "unknown") +
           "*";
  } else if (this->kind == TypeKind::OPTION) {
    // TODO - OPTION
    return "::txy::option<" +
           (this->inner_type ? this->inner_type->to_production() : "unknown") +
           ">";
  };

  string name = "unknown";

  // TODO - RANGE

  switch (this->kind) {
    case TypeKind::CHAR:
      name = "char";
      break;
    case TypeKind::STRING:
      name = "::std::string";
      break;
    case TypeKind::BOOL:
      name = "bool";
      break;
    case TypeKind::FLOAT:
      name = "float";
      break;
    case TypeKind::DOUBLE:
      name = "double";
      break;
    case TypeKind::LONG:
      name = "::std::int64_t";
      break;
    case TypeKind::INT:
      name = "::std::int32_t";
      break;
    case TypeKind::BYTE:
      name = "::std::uint8_t";
      break;
    case TypeKind::VOID:
      break;
    default:
      break;
  }

  return name;
};

// Construtores
Type::Type(TypeKind kind) : kind(kind), inner_type(nullptr) {};
Type::Type(TypeKind kind, Type* inner) : kind(kind), inner_type(inner) {};
Type::Type(TypeKind kind, string name) : kind(kind), name(name) {};