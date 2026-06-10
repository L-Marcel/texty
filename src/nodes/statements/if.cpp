#include "if.hpp"

// Debug
void IfNode::compile_dot(ostream& os) const {
  switch (this->type) {
    case IfType::EXPRESSION:
      Compiler::add_dot_node(os, this, "IF");
      Compiler::add_dot_relation(os, this, this->expression);
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children[i]);
      };
      Compiler::add_dot_relation(os, this, this->next);
      break;
    default:
      Compiler::add_dot_node(os, this, "IF: " + this->access_id);
      Compiler::add_dot_relation(os, this, this->access);
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children[i]);
      };
      Compiler::add_dot_relation(os, this, this->next);
      break;
  }
};

// Código
void IfNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type IfNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
IfNode::IfNode(int line, ExpressionNode* expression, IfEndNode* next)
    : Node(line), type(IfType::EXPRESSION), expression(expression), next(next) {
      };
IfNode::IfNode(int line, AccessNode* access, string access_id, IfEndNode* next)
    : Node(line),
      type(IfType::ACCESS),
      access(access),
      access_id(access_id),
      next(next) {};