#include "range.hpp"

#include "../../../helpers/numeric.hpp"

bool range_inclusion_to_bool(RangeInclusionType inclusion) {
  return inclusion == RangeInclusionType::INCLUSIVE;
};

// Debug
void RangeNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "RANGE");
  if (this->left_inclusion != RangeInclusionType::UNBOUNDED) {
    Compiler::add_dot_relation(os, this, this->left);
  };
  if (this->right_inclusion != RangeInclusionType::UNBOUNDED) {
    Compiler::add_dot_relation(os, this, this->right);
  };
};

// Código
void RangeNode::compile_code(ostream& os) const {
  Type type = this->get_type();

  os << "::txy::range<" << type.inner_type->to_production() << ">(";
  if (this->left_inclusion == RangeInclusionType::UNBOUNDED) {
    os << "::txy::unbounded_value{}";
  } else {
    this->left->compile_code(os);
  };

  os << ", ";

  if (this->right_inclusion == RangeInclusionType::UNBOUNDED) {
    os << "::txy::unbounded_value{}";
  } else {
    this->right->compile_code(os);
  };

  os << ", "
     << (range_inclusion_to_bool(this->left_inclusion) ? "true" : "false")
     << ", "
     << (range_inclusion_to_bool(this->right_inclusion) ? "true" : "false")
     << ")";
};

// Tipagem
Type RangeNode::get_type() const {
  if (this->left_inclusion != RangeInclusionType::UNBOUNDED &&
      this->right_inclusion != RangeInclusionType::UNBOUNDED) {
    Type left_type = this->left->get_type();
    Type right_type = this->right->get_type();

    if (!check_if_is_numeric(left_type) || left_type != right_type) {
      throw error("subfaixas não suportam limites do tipo (" +
                      left_type.to_string() + ", " + right_type.to_string() +
                      ")",
                  this->line);
    };

    return Type(TypeKind::RANGE, new Type(left_type));
  };

  if (this->left_inclusion != RangeInclusionType::UNBOUNDED) {
    Type left_type = this->left->get_type();
    if (!check_if_is_numeric(left_type)) {
      throw error("subfaixas não suportam limites do tipo (" +
                      left_type.to_string() + ")",
                  this->line);
    };

    return Type(TypeKind::RANGE, new Type(left_type));
  };

  Type right_type = this->right->get_type();
  if (!check_if_is_numeric(right_type)) {
    throw error("subfaixas não suportam limites do tipo (" +
                    right_type.to_string() + ")",
                this->line);
  };

  return Type(TypeKind::RANGE, new Type(right_type));
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
