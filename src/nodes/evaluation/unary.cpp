#include "unary.hpp"

// Debug
void UnaryOperationNode::print(ostream& os) const {
  Debug::print_node(os, this, string(magic_enum::enum_name(this->operation)));
  if (this->node) Debug::print_relation(os, this, this->node);
}

// Tipagem
Type UnaryOperationNode::get_type() const { return this->node->get_type(); };

// Construtores
ExpressionNode::~ExpressionNode() = default;
ExpressionNode::ExpressionNode(int line) : Node(line) {};
UnaryOperationNode::UnaryOperationNode(UnaryOperation operation,
                                       ExpressionNode* node)
    : ExpressionNode(node->line), operation(operation), node(node) {};
UnaryOperationNode::UnaryOperationNode(bool postfix, UnaryOperation operation,
                                       ExpressionNode* node)
    : ExpressionNode(node->line),
      operation(operation),
      postfix(postfix),
      node(node) {};