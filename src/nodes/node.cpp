#include "compiler.hpp"

// Debug
void Node::compile_dot(ostream& os) const {
  if (this->name == "")
    Compiler::add_dot_node(
        os, this, string(magic_enum::enum_name(this->get_type().kind)));
  else
    Compiler::add_dot_node(os, this, this->name);

  for (size_t i = 0; i < this->children.size(); i++) {
    Compiler::add_dot_relation(os, this, this->children.at(i));
  };
};

// Código
void Node::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type Node::get_type() const {
  for (size_t i = 0; i < this->children.size(); i++) {
    this->children.at(i)->get_type();
  };

  return Type(TypeKind::UNKNOWN);
};

// Construtores
Node::Node(int line) : children({}), name(""), line(line) {};
Node::Node(int line, string name) : children({}), name(name), line(line) {};