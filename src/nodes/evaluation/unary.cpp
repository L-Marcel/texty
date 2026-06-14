#include "unary.hpp"

#include "../../operations/unary/unary.hpp"

// Debug
void UnaryOperationNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->operation)));
  if (this->node) Compiler::add_dot_relation(os, this, this->node);
};

// Código
void UnaryOperationNode::compile_code(ostream& os) const {
  this->get_type();

  if (this->postfix) {
    os << "(";
    this->node->compile_code(os);
  } else {
    os << "(";
  };

  switch (operation) {
    case UnaryOperation::MINUS:
      os << "-";
      break;
    case UnaryOperation::REV:
      os << "~";
      break;
    case UnaryOperation::NOT:
      os << "!";
      break;
    case UnaryOperation::REF:
      os << "&";
      break;
    case UnaryOperation::DEREF:
      os << "*";
      break;
    case UnaryOperation::INCREMENT:
      os << "++";
      break;
    case UnaryOperation::DECREMENT:
      os << "--";
      break;
    default:
      throw error("operação unária \'" +
                      string(magic_enum::enum_name(this->operation)) +
                      "\' não implementada",
                  this->line);
  };

  if (!this->postfix) {
    this->node->compile_code(os);
  };

  os << ")";
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
