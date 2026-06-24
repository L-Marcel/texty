#include "struct_reference.hpp"

// Construtores
StructReference::StructReference(Type node_type, string name)
    : Reference(node_type, ReferenceType::STRUCT), name(name) {};

// Métodos
Reference* StructReference::get_property(string name) {
  if (this->properties.find(name) != this->properties.end()) {
    return this->properties[name];
  }
  return nullptr;
};
