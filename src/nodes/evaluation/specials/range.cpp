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
  type.get_name();

  string range_name = "range_" + type.inner_type->get_name();
  string type_production = type.inner_type->to_production();

  string type_enum;
  switch (type.inner_type->kind) {
    case TypeKind::BYTE:
      type_enum = "TYPE_BYTE";
      break;
    case TypeKind::INT:
      type_enum = "TYPE_INT";
      break;
    case TypeKind::LONG:
      type_enum = "TYPE_LONG";
      break;
    case TypeKind::FLOAT:
      type_enum = "TYPE_FLOAT";
      break;
    case TypeKind::DOUBLE:
      type_enum = "TYPE_DOUBLE";
      break;
    default:
      type_enum = "TYPE_UNBOUNDED";
      break;
  };

  string type_field;
  switch (type.inner_type->kind) {
    case TypeKind::BYTE:
      type_field = ".v_byte";
      break;
    case TypeKind::INT:
      type_field = ".v_int";
      break;
    case TypeKind::LONG:
      type_field = ".v_long";
      break;
    case TypeKind::FLOAT:
      type_field = ".v_float";
      break;
    case TypeKind::DOUBLE:
      type_field = ".v_double";
      break;
    default:
      type_field = "";
      break;
  };

  os << range_name << "_create(";

  if (this->left_inclusion == RangeInclusionType::UNBOUNDED) {
    os << "(bound_value){TYPE_UNBOUNDED, {0}}";
  } else {
    os << "(bound_value){" << type_enum << ", {" << type_field << " = ("
       << type_production << ")(";
    this->left->compile_code(os);
    os << ")}}";
  };

  os << ", ";

  if (this->right_inclusion == RangeInclusionType::UNBOUNDED) {
    os << "(bound_value){TYPE_UNBOUNDED, {0}}";
  } else {
    os << "(bound_value){" << type_enum << ", {" << type_field << " = ("
       << type_production << ")(";
    this->right->compile_code(os);
    os << ")}}";
  };

  os << ", " << (range_inclusion_to_bool(this->left_inclusion) ? "1" : "0")
     << ", " << (range_inclusion_to_bool(this->right_inclusion) ? "1" : "0")
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
