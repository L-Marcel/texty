#include "variable.hpp"
#include "../references.hpp"

// Construtores
VariableReference::VariableReference(Type node_type, bool is_const, string name_suffix)
    : Reference(node_type, ReferenceType::VARIABLE), is_const(is_const), name_suffix(name_suffix) {};

// Métodos
Reference* VariableReference::get_property(string name) {
  if (this->node_type.kind == TypeKind::NAMED) {
    try {
      Reference* ref = References::get_instance()->get_reference(-1, this->node_type.name);
      if (StructReference* struct_ref = dynamic_cast<StructReference*>(ref)) {
        return struct_ref->get_property(name);
      }
    } catch (...) {}
  } else if (this->node_type.kind == TypeKind::POINTER && this->node_type.inner_type->kind == TypeKind::NAMED) {
    try {
      Reference* ref = References::get_instance()->get_reference(-1, this->node_type.inner_type->name);
      if (StructReference* struct_ref = dynamic_cast<StructReference*>(ref)) {
        return struct_ref->get_property(name);
      }
    } catch (...) {}
  }
  return nullptr;
};
