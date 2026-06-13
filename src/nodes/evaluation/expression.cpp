#include "expression.hpp"

// Tipagem
void ExpressionNode::set_expected_type(Type type) {};

// Construtores
ExpressionNode::ExpressionNode(int line) : Node(line) {};
ExpressionNode::ExpressionNode(int line, string name) : Node(line, name) {};