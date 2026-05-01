#include "id.hpp"

#include "../references/references.hpp"

// Debug
void IdNode::print(ostream& os) const {
  Debug::print_node(os, this, this->name);
};

// Referência
Reference* IdNode::get_reference() const {
  return References::get_instance()->get_reference(this->name);
};

// Avaliação
Value IdNode::evaluate() {
  Reference* reference = this->get_reference();

  if (EvaluatableReference* evaluatable =
          dynamic_cast<EvaluatableReference*>(reference)) {
    return evaluatable->evaluate();
  };

  runtime_error("[ERROR] Tentativa inválida de acesso");
  return Value(Void{});
};

// Construtores
IdNode::IdNode(int line, string name) : ExpressionNode(line), name(name) {};