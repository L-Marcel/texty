#include "unary.hpp"

#include "../../operations/unary/unary.hpp"

static string unary_operation_to_production(UnaryOperation operation) {
  switch (operation) {
    case UnaryOperation::MINUS:
      return "-";
    case UnaryOperation::REV:
      return "~";
    case UnaryOperation::NOT:
      return "!";
    case UnaryOperation::REF:
      return "&";
    case UnaryOperation::DEREF:
      return "*";
    case UnaryOperation::INCREMENT:
      return "++";
    case UnaryOperation::DECREMENT:
      return "--";
  };
};

// Debug
void UnaryOperationNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->operation)));
  if (this->node) Compiler::add_dot_relation(os, this, this->node);
};

// Código
void UnaryOperationNode::compile_code(ostream& os) const {
  this->get_type();

  string operation = unary_operation_to_production(this->operation);
  if (this->postfix) {
    os << "(";
    this->node->compile_code(os);
    os << operation << ")";
  } else {
    os << "(" << operation;
    this->node->compile_code(os);
    os << ")";
  };
};

// Tipagem
Type UnaryOperationNode::get_type() const {
  Type node_type = this->node->get_type();
  UnaryTypeCheckFunction result =
      UnaryOperations::get_type(this->operation, this->line);
  return result(node_type, this->line);
};

// Construtores
UnaryOperationNode::UnaryOperationNode(UnaryOperation operation,
                                       ExpressionNode* node)
    : ExpressionNode(node->line), operation(operation), node(node) {};
UnaryOperationNode::UnaryOperationNode(bool postfix, UnaryOperation operation,
                                       ExpressionNode* node)
    : ExpressionNode(node->line),
      operation(operation),
      postfix(postfix),
      node(node) {};
