#include "unary.hpp"

// Debug
void UnaryOperationNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->operation)));
  if (this->node) Compiler::add_dot_relation(os, this, this->node);
}

// Código
void UnaryOperationNode::compile_code(ostream& os) const {
  // TODO
}

// Tipagem
Type UnaryOperationNode::get_type() const { return this->node->get_type(); };

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