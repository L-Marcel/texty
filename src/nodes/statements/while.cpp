#include "while.hpp"

// Debug
void WhileNode::compile_dot(ostream& os) const {
  switch (this->type) {
    case WhileType::WHILE:
      Compiler::add_dot_node(os, this, "WHILE");
      Compiler::add_dot_relation(os, this, this->condition);
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children[i]);
      };
      break;
    case WhileType::REPEAT:
      Compiler::add_dot_node(os, this, "REPEAT");
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children[i]);
      };
      Compiler::add_dot_relation(os, this, this->condition);
      break;
  }
};

// Código
void WhileNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type WhileNode::get_type() const { return Type(TypeKind::VOID); };

// Cobertura dos retornos
ReturnCoverage WhileNode::get_return_coverage() const {
  ReturnCoverage block_coverage = ReturnCoverage::NONE;

  for (size_t i = 0; i < this->children.size(); i++) {
    ReturnCoverage coverage = this->children[i]->get_return_coverage();
    
    if (coverage == ReturnCoverage::GUARANTEED) {
      if (this->type == WhileType::REPEAT) {
        block_coverage = ReturnCoverage::GUARANTEED;
      } else {
        block_coverage = ReturnCoverage::PARTIAL; 
      };
      
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
WhileNode::WhileNode(int line, ExpressionNode* condition, WhileType type)
    : Node(line), type(type), condition(condition) {};