#include "trait.hpp"

// Debug
void TraitNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "TRAIT: " + this->name);

  for (size_t i = 0; i < this->subprograms.size(); i++) {
    Compiler::add_dot_relation(os, this, this->subprograms[i]);
  };
};

// Código
void TraitNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type TraitNode::get_type() const { return Type(TypeKind::UNKNOWN); };

// Construtores
TraitNode::TraitNode(int line, string name, vector<SubprogramNode*> subprograms)
    : Node(line, name), subprograms(subprograms) {};