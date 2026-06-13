#include "option.hpp"

// Debug
void OptionNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "OPTION");
};

// Código
void OptionNode::compile_code(ostream& os) const {
  if (this->type == OptionNodeType::DEFINED) {
    os << "::txy::option(";
    this->value->compile_code(os);
    os << ")";
  } else {
    os << "::txy::option<";
    Type type = this->get_type();
    if (type.inner_type->kind == TypeKind::UNKNOWN) {
      throw error("tipo desconhecido para option", this->line);
    };

    os << type.inner_type->to_production();
    os << ">()";
  };
};

// Tipagem
void OptionNode::set_expected_type(Type type) {
  this->expected_type = Type(type);
};
Type OptionNode::get_type() const {
  if (this->type == OptionNodeType::DEFINED) {
    return Type(TypeKind::OPTION, new Type(this->value->get_type()));
  } else {
    return this->expected_type;
  };
};

// Construtores
OptionNode::OptionNode(int line)
    : ExpressionNode(line),
      type(OptionNodeType::UNDEFINED),
      value(nullptr),
      expected_type(Type(TypeKind::UNKNOWN)) {
  this->expected_type = Type(TypeKind::OPTION, new Type(TypeKind::UNKNOWN));
};
OptionNode::OptionNode(int line, ExpressionNode* value)
    : ExpressionNode(line),
      type(OptionNodeType::DEFINED),
      value(value),
      expected_type(Type(TypeKind::UNKNOWN)) {
  this->expected_type = Type(TypeKind::OPTION, new Type(TypeKind::UNKNOWN));
};