#include "debug.hpp"

// Debug
void Node::print(ostream& os) const {
  Debug::print_node(os, this, string(magic_enum::enum_name(this->get_type())));
};

// Tipagem
Type Node::get_type() const { return Type::UNKNOWN; };

// Construtores
Node::Node(int line) : line(line) {};