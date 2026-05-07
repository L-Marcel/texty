#include "procedure.hpp"

// Debug
void ProcedureNode::compile_dot(ostream& os) const {
  string params = params_to_string(this->params);
  Compiler::add_dot_node(os, this,
                         "PROCEDURE: " + this->name + "(" + params + ")");

  for (size_t i = 0; i < this->children.size(); i++) {
    Compiler::add_dot_relation(os, this, this->children.at(i));
  };
}

// Código
void ProcedureNode::compile_code(ostream& os) const {
  // TODO
}

// Tipagem
Type ProcedureNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
ProcedureNode::ProcedureNode(int line, string name,
                             vector<pair<string, Type>> params)
    : Node(line, name), params(params) {};