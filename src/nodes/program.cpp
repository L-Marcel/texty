#include "program.hpp"

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
  os << "#include <vector>" << std::endl;
  os << "#include <cstdint>" << std::endl;
  for (size_t i = 0; i < this->children.size(); i++) {
    this->children[i]->compile_code(os);
  };
};

// Tipagem
Type ProgramNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
ProgramNode::ProgramNode(int line) : Node(line, "PROGRAM") {};