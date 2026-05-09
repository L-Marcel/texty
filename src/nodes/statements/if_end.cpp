#include "if_end.hpp"

// Debug
void IfEndNode::compile_dot(ostream& os) const {
  switch (this->type) {
    case IfEndType::EXPRESSION:
      Compiler::add_dot_node(os, this, "ELIF");
      Compiler::add_dot_relation(os, this, this->expression);
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children.at(i));
      };
      Compiler::add_dot_relation(os, this, this->next);
      break;
    case IfEndType::ACCESS:
      Compiler::add_dot_node(os, this, "ELIF: " + this->access_id);
      Compiler::add_dot_relation(os, this, this->access);
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children.at(i));
      };
      Compiler::add_dot_relation(os, this, this->next);
      break;
    case IfEndType::ELSE:
      Compiler::add_dot_node(os, this, "ELSE");
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children.at(i));
      };
      Compiler::add_dot_relation(os, this, this->next);
      break;
    default:
      Compiler::add_dot_node(os, this, "END_IF");
      break;
  }
};

// Código
void IfEndNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type IfEndNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
IfEndNode::IfEndNode(int line, ExpressionNode* expression, IfEndNode* next)
    : Node(line),
      type(IfEndType::EXPRESSION),
      expression(expression),
      next(next) {};
IfEndNode::IfEndNode(int line, AccessNode* access, string access_id,
                     IfEndNode* next)
    : Node(line),
      type(IfEndType::ACCESS),
      access(access),
      access_id(access_id),
      next(next) {};
IfEndNode::IfEndNode(int line, IfEndNode* next)
    : Node(line), type(IfEndType::ELSE), next(next) {};
IfEndNode::IfEndNode(int line) : Node(line), type(IfEndType::END) {};