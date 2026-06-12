#include "attr.hpp"

#include "../../references/references.hpp"

// Debug
void AttrNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "ATTR: " + this->name.substr(4));
  Compiler::add_dot_relation(os, this, this->expression);
};

// Código
void AttrNode::compile_code(ostream& os) const {
  os << this->type.to_production() << " " << this->name << " = ";
  this->expression->compile_code(os);
  References::get_instance()->add_variable_reference(this->name, this->type,
                                                     false);
};

// Tipagem
Type AttrNode::get_type() const { return this->type; };

// Construtores
AttrNode::AttrNode(int line, string name, bool is_const, Type type,
                   ExpressionNode* expression)
    : Node(line, name), is_const(is_const), type(type), expression(expression) {
      };