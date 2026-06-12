#include "option.hpp"

// Debug
void OptionNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "OPTION");
};

// Código
void OptionNode::compile_code(ostream& os) const {
  os << "::txy::option(";
  this->value->compile_code(os);
  os << ")";
};

// Tipagem
Type OptionNode::get_type() const {
  if (this->type == OptionNodeType::DEFINED) {
    return Type(TypeKind::OPTION, new Type(this->value->get_type()));
  } else {
    return Type(TypeKind::OPTION, new Type(TypeKind::UNKNOWN));
  };
};

// Construtores
OptionNode::OptionNode(int line)
    : ExpressionNode(line), type(OptionNodeType::UNDEFINED), value(nullptr) {};
OptionNode::OptionNode(int line, ExpressionNode* value)
    : ExpressionNode(line), type(OptionNodeType::DEFINED), value(value) {};