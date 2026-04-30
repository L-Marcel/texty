#include "specials.h"

#include "../references/references.hpp"

// Debug
void IdNode::print(ostream& os) const {
  Debug::print_node(os, this, this->name);
}

// Tipagem
NodeType IdNode::get_type() const {
  Reference* reference = References::get_instance()->get_reference(this->name);
  if (reference != nullptr) {
    return reference->node_type;
  };

  return NodeType::UNKNOWN;
};
void IdNode::set_type(NodeType type) {
  References::get_instance()->declare(this->name, type,
                                      ReferenceType::VARIABLE);
};

// Construtores
IdNode::IdNode(int line, string name) : Node(line), name(name) {};
PointerNode::PointerNode(int line) : Node(line) {};
OptionNode::OptionNode(int line) : Node(line) {};