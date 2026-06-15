#include "binary.hpp"

#include "../../operations/binary/binary.hpp"
#include "specials/option.hpp"

// Debug
void BinaryOperationNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this,
                         string(magic_enum::enum_name(this->operation)));
  if (this->left) Compiler::add_dot_relation(os, this, this->left);
  if (this->right) Compiler::add_dot_relation(os, this, this->right);
};

// Código
void BinaryOperationNode::compile_code(ostream& os) const {
  os << "(";
  switch (this->operation) {
    case BinaryOperation::PLUS:
      this->left->compile_code(os);
      os << " + ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::MINUS:
      this->left->compile_code(os);
      os << " - ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::MULT:
      this->left->compile_code(os);
      os << " * ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::DIV:
      this->left->compile_code(os);
      os << " / ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::MOD:
      this->left->compile_code(os);
      os << " % ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::EXP:
      os << "::std::pow(";
      this->left->compile_code(os);
      os << ", ";
      this->right->compile_code(os);
      os << ")";
      break;
    case BinaryOperation::AND:
      this->left->compile_code(os);
      os << " && ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::OR:
      this->left->compile_code(os);
      os << " || ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::BITWISE_AND:
      this->left->compile_code(os);
      os << " & ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::BITWISE_OR:
      this->left->compile_code(os);
      os << " | ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::XOR:
      this->left->compile_code(os);
      os << " ^ ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::EQ:
      this->left->compile_code(os);
      os << " == ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::NOT_EQ:
      this->left->compile_code(os);
      os << " != ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::LT:
      this->left->compile_code(os);
      os << " < ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::GT:
      this->left->compile_code(os);
      os << " > ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::LT_EQ:
      this->left->compile_code(os);
      os << " <= ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::GT_EQ:
      this->left->compile_code(os);
      os << " >= ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::CONCAT:
      this->left->compile_code(os);
      os << " << ";
      this->right->compile_code(os);
      break;
    case BinaryOperation::IN: {
      Type type = this->right->get_type();
      if (type.kind == TypeKind::ARRAY || type.kind == TypeKind::RANGE) {
        this->right->compile_code(os);
        os << ".contains(";
        this->left->compile_code(os);
        os << ")";
      } else if (type.kind == TypeKind::OPTION) {
        OptionNode* right_option = dynamic_cast<OptionNode*>(this->right);
        OptionNode* left_option = dynamic_cast<OptionNode*>(this->left);

        if (right_option != nullptr && left_option != nullptr &&
            right_option->type == OptionNodeType::UNDEFINED &&
            left_option->type == OptionNodeType::UNDEFINED) {
          os << "true";
        } else {
          this->left->set_expected_type(this->right->get_type());
          this->left->compile_code(os);
          os << ".is_some() == ";
          this->right->compile_code(os);
          os << ".is_some()";
        };
      } else if (type.kind == TypeKind::STRING) {
        this->right->compile_code(os);
        os << ".find(";
        this->left->compile_code(os);
        os << ") != ::std::string::npos";
      };
      break;
    }
    default:
      throw error("operação binária \'" +
                      string(magic_enum::enum_name(this->operation)) +
                      "\' não implementada",
                  this->line);
  }
  os << ")";
};

// Tipagem
Type BinaryOperationNode::get_type() const {
  Type left = this->left->get_type();
  Type right = this->right->get_type();
  BinaryTypeCheckFunction result =
      BinaryOperations::get_type(this->operation, this->line);
  return result(left, right, this->line);
};

// Construtores
BinaryOperationNode::BinaryOperationNode(BinaryOperation operation,
                                         ExpressionNode* left,
                                         ExpressionNode* right)
    : ExpressionNode(left->line),
      operation(operation),
      left(left),
      right(right) {};