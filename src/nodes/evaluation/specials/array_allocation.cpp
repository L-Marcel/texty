#include "array_allocation.hpp"

// Debug
void ArrayAllocationNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(
      os, this,
      "new " +
          string(magic_enum::enum_name(this->get_type().inner_type->kind)) +
          "[]");

  if (this->size_type == ArrayAllocationSizeType::INITIAL_DEFINED) {
    Compiler::add_dot_node_item(os, this, "INITIAL_SIZE");
    Compiler::add_dot_node_item_relation(os, this, "INITIAL_SIZE",
                                         this->size_expression);
  };

  for (size_t i = 0; i < this->children.size(); i++) {
    Compiler::add_dot_relation(os, this, this->children[i]);
  };
};

// Código
void ArrayAllocationNode::compile_code(ostream& os) const {
  string name = "array_" + this->inner_type.get_name();
  string type_production = this->inner_type.to_production();

  if (this->children.empty() &&
      this->size_type == ArrayAllocationSizeType::UNDEFINED) {
    os << name << "_create(0, (" << type_production << ")0)";
  } else if (this->children.empty()) {
    os << name << "_create(";
    this->size_expression->compile_code(os);
    os << ", (" << type_production << ")0)";
  } else if (this->size_type == ArrayAllocationSizeType::UNDEFINED) {
    os << name << "_from_values((" << type_production << "[]){";
    for (size_t i = 0; i < this->children.size(); i++) {
      this->children[i]->compile_code(os);
      if (i != this->children.size() - 1) os << ", ";
    };
    os << "}, " << this->children.size() << ", " << this->children.size()
       << ", (" << type_production << ")0)";
  } else {
    os << name << "_from_values((" << type_production << "[]){";
    for (size_t i = 0; i < this->children.size(); i++) {
      this->children[i]->compile_code(os);
      if (i != this->children.size() - 1) os << ", ";
    };
    os << "}, " << this->children.size() << ", ";
    this->size_expression->compile_code(os);
    os << ", (" << type_production << ")0)";
  };
};

// Tipagem
Type ArrayAllocationNode::get_type() const {
  return Type(TypeKind::ARRAY, new Type(this->inner_type));
};

// Construtores
ArrayAllocationNode::ArrayAllocationNode(int line, Type inner_type,
                                         ExpressionNode* size_expression)
    : ExpressionNode(line),
      size_type(ArrayAllocationSizeType::INITIAL_DEFINED),
      inner_type(inner_type),
      size_expression(size_expression) {};
ArrayAllocationNode::ArrayAllocationNode(int line, Type inner_type)
    : ExpressionNode(line),
      size_type(ArrayAllocationSizeType::UNDEFINED),
      inner_type(inner_type),
      size_expression(nullptr) {};