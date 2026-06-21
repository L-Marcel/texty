#include "assign.hpp"

#include "../../operations/binary/binary.hpp"
#include "../evaluation/binary.hpp"

// Debug
void AssignNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "ASSIGN");
  Compiler::add_dot_relation(os, this, this->access);
  Compiler::add_dot_relation(os, this, this->expression);
};

// Código
void AssignNode::compile_code(ostream& os) const {
  if (this->assign_type == AssignType::SIMPLE) {
    this->get_type();
    this->access->compile_code(os);
    os << " = ";
    this->expression->compile_code(os);
  } else {
    this->get_type();
    this->access->compile_code(os);
    os << " = ";
    BinaryOperationNode operation =
        BinaryOperationNode(this->operation, this->access, this->expression);
    operation.compile_code(os);
  };
};

// Tipagem
Type AssignNode::get_type() const {
  Type left = this->access->get_type();
  Type right = this->expression->get_type();

  if ((
    left.kind == TypeKind::OPTION && right.kind == TypeKind::OPTION &&
      right.inner_type->kind == TypeKind::UNKNOWN
  ) || (
    left.kind == TypeKind::POINTER && right.kind == TypeKind::POINTER &&
      right.inner_type->kind == TypeKind::UNKNOWN
  )) {
    this->expression->set_expected_type(left);
    right = this->expression->get_type();
  };

  if (this->assign_type == AssignType::SIMPLE && left == right) {
    return this->access->get_type();
  } else if (this->assign_type == AssignType::OPERATION) {
    BinaryTypeCheckFunction result =
        BinaryOperations::get_type(this->operation, this->line);
    return result(left, right, this->line);
  } else {
    throw error("operação de atribuição '=' não definida para os tipos (" +
                    left.to_string() + ", " + right.to_string() + ")",
                this->line);
  };
};

// Construtores
AssignNode::AssignNode(int line, ExpressionNode* access, ExpressionNode* expression)
    : Node(line),
      assign_type(AssignType::SIMPLE),
      access(access),
      expression(expression) {};
AssignNode::AssignNode(int line, BinaryOperation operation, ExpressionNode* access,
                       ExpressionNode* expression)
    : Node(line),
      assign_type(AssignType::OPERATION),
      operation(operation),
      access(access),
      expression(expression) {};
