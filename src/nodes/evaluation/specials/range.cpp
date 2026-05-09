#include "range.hpp"

// Debug
void RangeNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "RANGE");
  if (this->left_inclusion != RangeInclusionType::UNBOUNDED) {
    Compiler::add_dot_relation(os, this, this->left);
  };
  if (this->right_inclusion != RangeInclusionType::UNBOUNDED) {
    Compiler::add_dot_relation(os, this, this->right);
  };
}

// Código
void RangeNode::compile_code(ostream& os) const {
  // TODO
}

// Tipagem
Type RangeNode::get_type() const {
  if (this->left_inclusion != RangeInclusionType::UNBOUNDED) {
    return Type(TypeKind::RANGE, new Type(this->left->get_type()));
  } else {
    return Type(TypeKind::RANGE, new Type(this->right->get_type()));
  };
};

// Construtores
RangeNode::RangeNode(int line, bool left, ExpressionNode* expression,
                     RangeInclusionType expression_inclusion)
    : ExpressionNode(line) {
  if (left) {
    this->left = expression;
    this->left_inclusion = expression_inclusion;
    this->right_inclusion = RangeInclusionType::UNBOUNDED;
  } else {
    this->left_inclusion = RangeInclusionType::UNBOUNDED;
    this->right = expression;
    this->right_inclusion = expression_inclusion;
  };
};
RangeNode::RangeNode(int line, ExpressionNode* left,
                     RangeInclusionType left_inclusion, ExpressionNode* right,
                     RangeInclusionType right_inclusion)
    : ExpressionNode(line),
      left(left),
      left_inclusion(left_inclusion),
      right(right),
      right_inclusion(right_inclusion) {};