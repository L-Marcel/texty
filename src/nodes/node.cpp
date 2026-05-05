#include "compiler.hpp"

// Debug
void Node::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->get_type())));
};

// Código
void Node::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type Node::get_type() const { return Type::UNKNOWN; };

// Construtores
Node::Node(int line) : line(line) {};