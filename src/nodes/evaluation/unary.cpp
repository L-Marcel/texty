#include "unary.hpp"

#include "../../lib/magic_enum.hpp"
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

  bool ignore_parenthesis = false;
  if (operation == UnaryOperation::REF || operation == UnaryOperation::DEREF) {
      Type node_type = this->node->get_type();
      if (operation == UnaryOperation::REF && node_type.kind == TypeKind::NAMED) {
          ignore_parenthesis = true;
      } else if (operation == UnaryOperation::DEREF && node_type.kind == TypeKind::POINTER && node_type.inner_type != nullptr && node_type.inner_type->kind == TypeKind::NAMED) {
          ignore_parenthesis = true;
      }
  }

  if (!ignore_parenthesis) {
      if (this->postfix) {
        os << "(";
        this->node->compile_code(os);
      } else {
        os << "(";
      };
  }

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
    case UnaryOperation::REF: {
      Type node_type = this->node->get_type();
      if (node_type.kind == TypeKind::NAMED) {
          this->node->compile_code(os);
          return;
      }
      os << "&";
      break;
    }
    case UnaryOperation::DEREF: {
      Type node_type = this->node->get_type();
      if (node_type.kind == TypeKind::POINTER && node_type.inner_type != nullptr && node_type.inner_type->kind == TypeKind::NAMED) {
          this->node->compile_code(os);
          return;
      }
      os << "*";
      break;
    }
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
