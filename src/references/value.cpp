#include "value.hpp"

#include "../lib/magic_enum.hpp"
#include "../nodes/compiler.hpp"

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
  switch (this->kind) {
    case TypeKind::NAMED:
      return this->name;
    case TypeKind::ARRAY:
      return (this->inner_type ? this->inner_type->to_string() : "unknown") +
             "[]";
    case TypeKind::RANGE:
      return "range<" +
             (this->inner_type ? this->inner_type->to_string() : "unknown") +
             ">";
    case TypeKind::POINTER:
      return "pointer<" +
             (this->inner_type ? this->inner_type->to_string() : "unknown") +
             ">";
    case TypeKind::OPTION:
      return "option<" +
             (this->inner_type ? this->inner_type->to_string() : "unknown") +
             ">";
    default: {
      string name = string(magic_enum::enum_name(this->kind));
      transform(name.begin(), name.end(), name.begin(), ::tolower);
      return name;
    }
  }
};

string Type::to_production() const {
  switch (this->kind) {
    case TypeKind::NAMED:
      return this->name;
    case TypeKind::ARRAY:
    case TypeKind::RANGE:
    case TypeKind::OPTION:
      return this->get_name();
    case TypeKind::POINTER:
      return (this->inner_type ? this->inner_type->to_production()
                               : "unknown") +
             "*";
    case TypeKind::CHAR:
      return "char";
    case TypeKind::STRING:
      return "char*";
    case TypeKind::BOOL:
    case TypeKind::BYTE:
      return "uint8_t";
    case TypeKind::FLOAT:
      return "float";
    case TypeKind::DOUBLE:
      return "double";
    case TypeKind::LONG:
      return "int64_t";
    case TypeKind::INT:
      return "int32_t";
    case TypeKind::VOID:
      return "void";
    default:
      return "unknown";
  }
};

string Type::get_name() const {
  switch (this->kind) {
    case TypeKind::NAMED:
      return this->name;
    case TypeKind::ARRAY:
      if (this->inner_type) Compiler::register_array(*this->inner_type);
      return "array_" +
             (this->inner_type ? this->inner_type->get_name() : "unknown");
    case TypeKind::RANGE:
      return "range_" +
             (this->inner_type ? this->inner_type->get_name() : "unknown");
    case TypeKind::POINTER:
      return "pointer_" +
             (this->inner_type ? this->inner_type->get_name() : "unknown");
    case TypeKind::OPTION:
      if (this->inner_type) Compiler::register_option(*this->inner_type);
      return "option_" +
             (this->inner_type ? this->inner_type->get_name() : "unknown");
    default: {
      string name = string(magic_enum::enum_name(this->kind));
      transform(name.begin(), name.end(), name.begin(), ::tolower);
      return name;
    }
  }
};

string Type::get_default_value() const {
  switch (this->kind) {
    case TypeKind::STRING:
      return "(char*)(\"\")";
    case TypeKind::CHAR:
      return "'\\0'";
    case TypeKind::BOOL:
    case TypeKind::BYTE:
      return "((uint8_t)0)";
    case TypeKind::INT:
      return "((int32_t)0)";
    case TypeKind::LONG:
      return "((int64_t)0LL)";
    case TypeKind::FLOAT:
      return "0.0f";
    case TypeKind::DOUBLE:
      return "0.0";
    case TypeKind::OPTION:
      return this->get_name() + "_none()";
    case TypeKind::ARRAY:
      return this->get_name() + "_empty()";
    case TypeKind::NAMED:
      return this->name + "_default()";
    default:
      return "0";
  }
};

// Construtores
Type::Type(TypeKind kind) : kind(kind), inner_type(nullptr) {};
Type::Type(TypeKind kind, Type* inner) : kind(kind), inner_type(inner) {};
Type::Type(TypeKind kind, string name) : kind(kind), name(name) {};
