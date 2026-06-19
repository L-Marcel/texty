#include "case.hpp"

// Debug
void CaseNode::compile_dot(ostream& os) const {
  switch (this->type) {
    case CaseType::CASE:
      Compiler::add_dot_node(os, this, "CASE");
      for (size_t i = 0; i < this->expressions.size(); i++) {
        Compiler::add_dot_relation(os, this, this->expressions[i]);
      };
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children[i]);
      };
      break;
    case CaseType::DEFAULT:
      Compiler::add_dot_node(os, this, "DEFAULT");
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children[i]);
      };
      break;
  }
};

// Código
void CaseNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type CaseNode::get_type() const { return Type(TypeKind::VOID); };

// Cobertura do retorno
ReturnCoverage CaseNode::get_return_coverage() const {
  ReturnCoverage block_coverage = ReturnCoverage::NONE;

  for (size_t i = 0; i < this->children.size(); i++) {
    ReturnCoverage coverage = this->children[i]->get_return_coverage();
    
    if (coverage == ReturnCoverage::GUARANTEED) {
      block_coverage = ReturnCoverage::GUARANTEED;
      
      if (i + 1 < this->children.size()) {
        throw error("código inalcançável detectado após instrução de retorno", 
                    this->children[i + 1]->line);
      };
      
      break;
    } else if (coverage == ReturnCoverage::PARTIAL) {
      block_coverage = ReturnCoverage::PARTIAL;
    };
  };

  return block_coverage;
};

// Construtores
CaseNode::CaseNode(int line, vector<ExpressionNode*> expressions)
    : Node(line), type(CaseType::CASE), expressions(expressions) {};
CaseNode::CaseNode(int line)
    : Node(line),
      type(CaseType::DEFAULT),
      expressions(vector<ExpressionNode*>()) {};