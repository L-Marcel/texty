#include "for.hpp"

// Debug
void ForNode::compile_dot(ostream& os) const {
  switch (this->type) {
    case ForType::SINGLE_EXPRESSION:
      Compiler::add_dot_node(os, this, "FOR: " + this->name.substr(4));
      Compiler::add_dot_relation(os, this, this->expression);
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children[i]);
      };
      break;
    case ForType::THREE_EXPRESSION:
      Compiler::add_dot_node(os, this, "FOR");
      Compiler::add_dot_relation(os, this, this->attr);
      Compiler::add_dot_relation(os, this, this->condition);
      Compiler::add_dot_relation(os, this, this->increment);
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children[i]);
      };
      break;
  }
};

// Código
void ForNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type ForNode::get_type() const { return Type(TypeKind::VOID); };

// Cobertura dos retornos
ReturnCoverage ForNode::get_return_coverage() const {
  ReturnCoverage block_coverage = ReturnCoverage::NONE;

  for (size_t i = 0; i < this->children.size(); i++) {
    ReturnCoverage coverage = this->children[i]->get_return_coverage();
    
    if (coverage == ReturnCoverage::GUARANTEED) {
      block_coverage = ReturnCoverage::PARTIAL; 
      
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
ForNode::ForNode(int line, string name, ExpressionNode* expression)
    : Node(line, name),
      type(ForType::SINGLE_EXPRESSION),
      expression(expression) {};
ForNode::ForNode(int line, AttrNode* attr, ExpressionNode* condition,
                 ExpressionNode* increment)
    : Node(line), attr(attr), condition(condition), increment(increment) {};