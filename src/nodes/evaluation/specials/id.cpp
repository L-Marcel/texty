#include "id.hpp"

#include "../../../references/references.hpp"
#include "../../../references/variables/variable.hpp"

// Debug
void IdNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, this->name.substr(4));
};

// Código
void IdNode::compile_code(ostream& os) const {
  Reference* ref =
      References::get_instance()->get_reference(this->line, this->name);
  if (ref->reference_type == ReferenceType::VARIABLE) {
    VariableReference* variable_reference = (VariableReference*)ref;
    os << this->name << variable_reference->name_suffix;
  } else {
    os << this->name;
  };
};

// Tipagem
Type IdNode::get_type() const {
  return References::get_instance()
      ->get_reference(this->line, this->name)
      ->node_type;
};

// Construtores
IdNode::IdNode(int line, string name) : ExpressionNode(line), name(name) {};