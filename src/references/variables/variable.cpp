#include "variable.hpp"
#include "../references.hpp"

// Construtores
VariableReference::VariableReference(Type node_type, bool is_const, string name_suffix)
    : Reference(node_type, ReferenceType::VARIABLE), is_const(is_const), name_suffix(name_suffix) {};

// Métodos
Reference* VariableReference::get_property(string name) {
  if (this->node_type.kind == TypeKind::NAMED) {
    if (References::get_instance()->struct_references.find(this->node_type.name) != References::get_instance()->struct_references.end()) {
      return References::get_instance()->struct_references[this->node_type.name]->get_property(name);
    }
  } else if (this->node_type.kind == TypeKind::POINTER && this->node_type.inner_type->kind == TypeKind::NAMED) {
    if (References::get_instance()->struct_references.find(this->node_type.inner_type->name) != References::get_instance()->struct_references.end()) {
      return References::get_instance()->struct_references[this->node_type.inner_type->name]->get_property(name);
    }
  }
  return nullptr;
};
