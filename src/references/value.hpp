#pragma once
#include "../includes.hpp"

struct Type {
  TypeKind kind;
  Type* inner_type;
  string name;

  Type(TypeKind kind);
  Type(TypeKind kind, Type* inner);
  Type(TypeKind kind, string name);
  bool operator==(const Type& a) const;
  bool operator!=(const Type& a) const;
  bool operator<(const Type& a) const;
  string to_string() const;
  string to_production() const;
  string get_name() const;
  string get_default_value() const;
};