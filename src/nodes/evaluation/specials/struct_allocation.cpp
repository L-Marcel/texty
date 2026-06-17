#include "struct_allocation.hpp"

// Debug
void StructAllocationNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "new " + this->name.substr(4));
  for (size_t i = 0; i < this->attributes.size(); i++) {
    pair<string, ExpressionNode*> attribute = this->attributes[i];
    Compiler::add_dot_node_item(os, this, attribute.first);
    Compiler::add_dot_node_item_relation(os, this, attribute.first,
                                         attribute.second);
  };
};

// Código
void StructAllocationNode::compile_code(ostream& os) const {
  os << "({" << this->name << " instance = " << this->name << "_default(); ";
  for (size_t i = 0; i < this->attributes.size(); i++) {
    os << "instance." << this->attributes[i].first << " = ";
    this->attributes[i].second->compile_code(os);
    os << "; ";
  }
  os << "instance; })";
};

// Tipagem
Type StructAllocationNode::get_type() const {
  return Type(TypeKind::NAMED, this->name);
};

// Construtores
StructAllocationNode::StructAllocationNode(
    int line, string name, vector<pair<string, ExpressionNode*>> attributes)
    : ExpressionNode(line, name), attributes(attributes) {};