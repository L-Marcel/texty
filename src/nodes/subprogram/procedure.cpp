#include "procedure.hpp"

#include "../../references/references.hpp"

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
  vector<Type> types = vector<Type>();
  for (size_t i = 0; i < this->params.size(); i++) {
    types.push_back(this->params[i].second);
  };

  References::get_instance()->add_procedure_reference(this->name, types);
  References::get_instance()->push_scope();
  for (size_t i = 0; i < this->children.size(); i++) {
    this->children.at(i)->compile_code(os);
  };
  References::get_instance()->pop_scope();
}

// Tipagem
Type ProcedureNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
ProcedureNode::ProcedureNode(int line, string name,
                             vector<pair<string, Type>> params)
    : Node(line, name), params(params) {};