#include "access_base.hpp"

// Debug
void AccessBaseNode::compile_dot(ostream& os) const {
  switch (this->access_type) {
    case AccessBaseType::ID:
      Compiler::add_dot_node(os, this, "ID: " + this->name);
      break;
    case AccessBaseType::SELF:
      Compiler::add_dot_node(os, this, "SELF");
      break;
    case AccessBaseType::EXPR:
      Compiler::add_dot_node(os, this, "ACCESS");
      Compiler::add_dot_relation(os, this, this->expression);
      break;
    default:
      break;
  }
};

// Código
void AccessBaseNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type AccessBaseNode::get_type() const {
  // TODO
  return Type(TypeKind::UNKNOWN);
};

// Construtores
AccessBaseNode::AccessBaseNode(int line)
    : Node(line), access_type(AccessBaseType::SELF) {};
AccessBaseNode::AccessBaseNode(int line, string name)
    : Node(line, name), access_type(AccessBaseType::ID) {};
AccessBaseNode::AccessBaseNode(int line, ExpressionNode* expression)
    : Node(line), access_type(AccessBaseType::EXPR), expression(expression) {};