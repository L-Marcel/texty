#include "assign.hpp"

#include "../../operations/binary/binary.hpp"

// Debug
void AssignNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "ASSIGN");
  Compiler::add_dot_relation(os, this, this->access);
  Compiler::add_dot_relation(os, this, this->expression);
};

// Código
void AssignNode::compile_code(ostream& os) const {
  this->access->compile_code(os);
  os << " = ";
  this->expression->compile_code(os);
  this->get_type();
};

// Tipagem
Type AssignNode::get_type() const {
  Type left = this->access->get_type();
  Type right = this->expression->get_type();

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
AssignNode::AssignNode(int line, AccessNode* access, ExpressionNode* expression)
    : Node(line),
      assign_type(AssignType::SIMPLE),
      access(access),
      expression(expression) {};
AssignNode::AssignNode(int line, BinaryOperation operation, AccessNode* access,
                       ExpressionNode* expression)
    : Node(line),
      assign_type(AssignType::OPERATION),
      access(access),
      expression(expression) {};