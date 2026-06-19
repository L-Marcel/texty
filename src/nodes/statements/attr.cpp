#include "attr.hpp"

#include "../../references/references.hpp"

// Debug
void AttrNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "ATTR: " + this->name.substr(4));
  Compiler::add_dot_relation(os, this, this->expression);
};

// Código
void AttrNode::compile_code(ostream& os) const {
  Type expression_type = this->expression->get_type();
  if (this->type.kind == TypeKind::OPTION &&
      expression_type.kind == TypeKind::OPTION &&
      expression_type.inner_type->kind == TypeKind::UNKNOWN) {
    this->expression->set_expected_type(this->type);
  } else if (this->type.kind != TypeKind::UNKNOWN &&
             this->type != expression_type) {
    throw error("variável '" + this->name.substr(4) + "' é do tipo (" +
                    this->type.to_string() + "), mas a expressão é do tipo (" +
                    expression_type.to_string() + ")",
                this->line);
  };

  if (References::get_instance()->has_reference_in_current_scope(
          this->name, ReferenceType::VARIABLE)) {
    throw error(
        "variável '" + this->name.substr(4) + "' já foi declarada neste escopo",
        this->line);
  };

  string name_suffix = References::get_instance()->add_variable_reference(
      this->name, this->type, false);

  os << this->type.to_production() << " " << this->name << name_suffix << " = ";
  this->expression->compile_code(os);
};

// Tipagem
Type AttrNode::get_type() const { return this->type; };

// Construtores
AttrNode::AttrNode(int line, string name, bool is_const, Type type,
                   ExpressionNode* expression)
    : Node(line, name), is_const(is_const), type(type), expression(expression) {
      };