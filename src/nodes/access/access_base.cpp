#include "access_base.hpp"

#include "../../references/references.hpp"

// Debug
void AccessBaseNode::compile_dot(ostream& os) const {
  switch (this->access_type) {
    case AccessBaseType::ID:
      Compiler::add_dot_node(os, this, "ID: " + this->name.substr(4));
      break;
    case AccessBaseType::SELF:
      Compiler::add_dot_node(os, this, "SELF");
      break;
    case AccessBaseType::EXPRESSION:
      Compiler::add_dot_node(os, this, "ACCESS");
      Compiler::add_dot_relation(os, this, this->expression);
      break;
    default:
      break;
  }
};

// Código
void AccessBaseNode::compile_code(ostream& os) const {
  switch (this->access_type) {
    case AccessBaseType::ID:
      os << this->name;
      break;
    case AccessBaseType::SELF:
      os << "this";
      break;
    default:
      this->expression->compile_code(os);
      break;
  };
};

// Tipagem
Type AccessBaseNode::get_type() const {
  Reference* reference = this->get_reference(this->line);
  return reference->node_type;
};

// Referências
Reference* AccessBaseNode::get_reference(int line) const {
  switch (this->access_type) {
    case AccessBaseType::ID:
      return References::get_instance()->get_reference(line, this->name);
    case AccessBaseType::SELF:
      return References::get_instance()->get_reference(line, "self");
    default:
      return new Reference(this->expression->get_type(),
                           ReferenceType::EXPRESSION);
  };
};

// Construtores
AccessBaseNode::AccessBaseNode(int line)
    : Node(line), access_type(AccessBaseType::SELF) {};
AccessBaseNode::AccessBaseNode(int line, string name)
    : Node(line, name), access_type(AccessBaseType::ID) {};
AccessBaseNode::AccessBaseNode(int line, ExpressionNode* expression)
    : Node(line),
      access_type(AccessBaseType::EXPRESSION),
      expression(expression) {};