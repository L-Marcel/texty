#include "impl.hpp"

// Debug
void ImplNode::compile_dot(ostream& os) const {
  if (this->target == "")
    Compiler::add_dot_node(os, this, "IMPL: " + this->name);
  else
    Compiler::add_dot_node(os, this,
                           "IMPL: (" + this->name + ", " + this->target + ")");
  for (size_t i = 0; i < this->subprograms.size(); i++) {
    Compiler::add_dot_relation(os, this, this->subprograms.at(i));
  };
};

// Código
void ImplNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type ImplNode::get_type() const { return Type(TypeKind::UNKNOWN); };

// Construtores
ImplNode::ImplNode(int line, string name, vector<SubprogramNode*> subprograms)
    : Node(line, name), target(""), subprograms(subprograms) {};
ImplNode::ImplNode(int line, string name, string target,
                   vector<SubprogramNode*> subprograms)
    : Node(line, name), target(target), subprograms(subprograms) {};