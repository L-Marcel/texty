#include "unary.hpp"

// Debug
void UnaryOperationNode::print(ostream& os) const {
  Debug::print_node(os, this, string(magic_enum::enum_name(this->operation)));
  if (this->node) Debug::print_relation(os, this, this->node);
}

// Tipagem
Type UnaryOperationNode::get_type() const { return this->node->get_type(); };

// Avaliação
Value UnaryOperationNode::evaluate() {
  throw error("operação não definida", this->line);
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