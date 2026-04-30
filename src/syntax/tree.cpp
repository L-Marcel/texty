#include "../references/references.hpp"

// Debug
void Node::print(ostream& os) const {
  Debug::print_node(os, this, string(magic_enum::enum_name(this->get_type())));
}
void BinaryOperationNode::print(ostream& os) const {
  Debug::print_node(os, this, string(magic_enum::enum_name(this->operation)));
  if (this->left) Debug::print_relation(os, this, this->left);
  if (this->right) Debug::print_relation(os, this, this->right);
}
void UnaryOperationNode::print(ostream& os) const {
  Debug::print_node(os, this, string(magic_enum::enum_name(this->operation)));
  if (this->node) Debug::print_relation(os, this, this->node);
}

// Tipagem
NodeType Node::get_type() const { return NodeType::UNKNOWN; };
NodeType BinaryOperationNode::get_type() const {
  return this->left->get_type();
};
NodeType UnaryOperationNode::get_type() const {
  return this->node->get_type();
};

// Construtores
Node::~Node() = default;
Node::Node(int line) : line(line) {};
BinaryOperationNode::BinaryOperationNode(BinaryOperation operation, Node* left,
                                         Node* right)
    : Node(left->line), operation(operation), left(left), right(right) {};
UnaryOperationNode::UnaryOperationNode(UnaryOperation operation, Node* node)
    : Node(node->line), operation(operation), node(node) {};
UnaryOperationNode::UnaryOperationNode(bool postfix, UnaryOperation operation,
                                       Node* node)
    : Node(node->line), operation(operation), postfix(postfix), node(node) {};