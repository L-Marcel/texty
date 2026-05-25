#include "case.hpp"

// Debug
void CaseNode::compile_dot(ostream& os) const {
  switch (this->type) {
    case CaseType::CASE:
      Compiler::add_dot_node(os, this, "CASE");
      for (size_t i = 0; i < this->expressions.size(); i++) {
        Compiler::add_dot_relation(os, this, this->expressions.at(i));
      };
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children.at(i));
      };
      break;
    case CaseType::DEFAULT:
      Compiler::add_dot_node(os, this, "DEFAULT");
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children.at(i));
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

// Construtores
CaseNode::CaseNode(int line, vector<ExpressionNode*> expressions)
    : Node(line), type(CaseType::CASE), expressions(expressions) {};
CaseNode::CaseNode(int line)
    : Node(line),
      type(CaseType::DEFAULT),
      expressions(vector<ExpressionNode*>()) {};