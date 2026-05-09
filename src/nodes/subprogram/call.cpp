#include "call.hpp"

#include "../../references/references.hpp"

// Debug
void SubprogramCallNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "CALL");
  for (size_t i = 0; i < this->params.size(); i++) {
    Compiler::add_dot_relation(os, this, this->params.at(i));
  };
}

// Código
void SubprogramCallNode::compile_code(ostream& os) const {
  // TODO
  this->get_type();
}

// Tipagem
Type SubprogramCallNode::get_type() const {
  if (this->call_type == CallType::ACCESS) {
    Reference* reference = this->access->get_reference(this->line);

    vector<Type> types;
    if (reference->reference_type == ReferenceType::FUNCTION) {
      FunctionReference* function_reference = (FunctionReference*)reference;

      if (function_reference->params.size() != this->params.size()) {
        throw error("número de parâmetros incorreto", this->line);
      };

      for (size_t i = 0; i < function_reference->params.size(); i++) {
        if (this->params[i]->get_type() != function_reference->params[i]) {
          throw error("tipo incorreto nos parâmetros da chamada", this->line);
        };
      };

      return function_reference->node_type;
    } else if (reference->reference_type == ReferenceType::PROCEDURE) {
      ProcedureReference* procedure_reference = (ProcedureReference*)reference;

      if (procedure_reference->params.size() != this->params.size()) {
        throw error("número de parâmetros incorreto", this->line);
      };

      for (size_t i = 0; i < procedure_reference->params.size(); i++) {
        if (this->params[i]->get_type() != procedure_reference->params[i]) {
          throw error("tipo incorreto nos parâmetros da chamada", this->line);
        };
      };

      return Type(TypeKind::VOID);
    } else {
      throw error("identificador não pertence a um subprograma", this->line);
    };
  } else {
    // TODO
    return this->target_type;
  };
};

// Construtores
SubprogramCallNode::SubprogramCallNode(int line, AccessNode* access,
                                       vector<ExpressionNode*> params)
    : Node(line),
      call_type(CallType::ACCESS),
      access(access),
      params(params),
      target_type(Type(TypeKind::UNKNOWN)) {};
SubprogramCallNode::SubprogramCallNode(int line, Type target_type,
                                       vector<ExpressionNode*> params)
    : Node(line),
      call_type(CallType::CONVERTION),
      params(params),
      target_type(target_type) {};