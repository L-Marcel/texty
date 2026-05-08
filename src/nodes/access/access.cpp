#include "access.hpp"

// Debug
void AccessNode::compile_dot(ostream& os) const {
  switch (this->access_type) {
    case AccessType::DOT:
      Compiler::add_dot_node(os, this, "DOT: " + this->name);
      Compiler::add_dot_relation(os, this, this->previous);
      break;
    case AccessType::BRACKET:
      Compiler::add_dot_node(os, this, "BRACKET");
      Compiler::add_dot_relation(os, this, this->previous);
      Compiler::add_dot_relation(os, this, this->expression);
      break;
    case AccessType::CALL:
      Compiler::add_dot_node(os, this, "ACCESS");
      Compiler::add_dot_relation(os, this, this->call);
      break;
    case AccessType::STATIC:
      Compiler::add_dot_node(os, this, "STATIC: " + this->name);
      Compiler::add_dot_relation(os, this, this->previous);
      break;
    case AccessType::BASE:
      Compiler::add_dot_node(os, this, "ACCESS");
      Compiler::add_dot_relation(os, this, this->base);
      break;
    default:
      break;
  }
};

// Código
void AccessNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type AccessNode::get_type() const {
  // TODO
  return Type(TypeKind::UNKNOWN);
};

// Construtores
AccessNode::AccessNode(int line, AccessBaseNode* base)
    : ExpressionNode(line), access_type(AccessType::BASE), base(base) {};
AccessNode::AccessNode(int line, Node* call)
    : ExpressionNode(line), access_type(AccessType::CALL), call(call) {};
AccessNode::AccessNode(int line, string name, AccessNode* previous,
                       AccessType access_type)
    : ExpressionNode(line, name),
      access_type(access_type),
      previous(previous) {};
AccessNode::AccessNode(int line, AccessNode* previous,
                       ExpressionNode* expression)
    : ExpressionNode(line),
      access_type(AccessType::BRACKET),
      previous(previous),
      expression(expression) {};