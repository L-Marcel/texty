#include "program.hpp"

#include "../references/references.hpp"
#include "compiler.hpp"

// Debug
void ProgramNode::compile_dot(ostream& os) const {
  if (this->name == "")
    Compiler::add_dot_node(
        os, this, string(magic_enum::enum_name(this->get_type().kind)));
  else
    Compiler::add_dot_node(os, this, this->name);

  for (size_t i = 0; i < this->children.size(); i++) {
    Compiler::add_dot_relation(os, this, this->children[i]);
  };
};

// Código
void ProgramNode::compile_code(ostream& os) const {
  References::get_instance()->push_scope();
  References::get_instance()->initialize();

  for (size_t i = 0; i < this->children.size(); i++) {
    this->children[i]->compile_code(os);
  };

  bool has_main_as_procedure = References::get_instance()->has_reference(
      "txy_main", ReferenceType::PROCEDURE);
  bool has_main_as_function = References::get_instance()->has_reference(
      "txy_main", ReferenceType::FUNCTION);

  if (!has_main_as_function && !has_main_as_procedure) {
    throw error("subprograma main não declarado");
  }

  References::get_instance()->pop_scope();
};

// Tipagem
Type ProgramNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
ProgramNode::ProgramNode(int line) : Node(line, "PROGRAM") {};