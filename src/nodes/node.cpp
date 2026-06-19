#include "compiler.hpp"

#include "../lib/magic_enum.hpp"

// Debug
void Node::compile_dot(ostream& os) const {
  if (this->name == "")
    Compiler::add_dot_node(
        os, this, string(magic_enum::enum_name(this->get_type().kind)));
  else
    Compiler::add_dot_node(os, this, this->name.substr(4));

  for (size_t i = 0; i < this->children.size(); i++) {
    Compiler::add_dot_relation(os, this, this->children[i]);
  };
};

// Código
void Node::compile_code(ostream& os) const {
  for (size_t i = 0; i < this->children.size(); i++) {
    this->children[i]->compile_code(os);
  };
};

// Tipagem
Type Node::get_type() const { return Type(TypeKind::UNKNOWN); };

// Cobertura de retorno
ReturnCoverage Node::get_return_coverage() const {
  return ReturnCoverage::NONE;
};

// Construtores
Node::Node(int line) : children({}), name(""), line(line) {};
Node::Node(int line, string name) : children({}), name(name), line(line) {};
