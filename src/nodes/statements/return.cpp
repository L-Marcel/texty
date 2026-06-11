#include "return.hpp"

// Debug
void ReturnNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "RETURN");
  Compiler::add_dot_relation(os, this, this->expression);
};

// Código
void ReturnNode::compile_code(ostream& os) const {
  os << "return ";
  this->expression->compile_code(os);
  os << ";" << std::endl;
};

// Tipagem
Type ReturnNode::get_type() const { return this->expression->get_type(); };

// Construtores
ReturnNode::ReturnNode(int line, ExpressionNode* expression)
    : Node(line), expression(expression) {};
