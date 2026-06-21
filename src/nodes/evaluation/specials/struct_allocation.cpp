#include "struct_allocation.hpp"

#include "../../../references/references.hpp"

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
  References* references = References::get_instance();
  if (!references->has_struct_reference(this->name)) {
    throw error("tentativa inválida de alocação da estrutura '" +
                    this->name.substr(4) + "' não declarada",
                this->line);
  }
  vector<pair<string, Type>> struct_attributes =
      references->get_struct_reference(this->name);

  vector<string> initialized_attributes;
  for (size_t i = 0; i < this->attributes.size(); i++) {
    string attribute_name = this->attributes[i].first;
    for (size_t j = 0; j < initialized_attributes.size(); j++) {
      if (initialized_attributes[j] == attribute_name) {
        throw error("campo '" + attribute_name.substr(4) +
                        "' inicializado mais de uma vez na estrutura '" +
                        this->name.substr(4) + "'",
                    this->line);
      }
    }
    initialized_attributes.push_back(attribute_name);

    bool found_attribute = false;
    for (size_t j = 0; j < struct_attributes.size(); j++) {
      if (struct_attributes[j].first == attribute_name) {
        found_attribute = true;
        break;
      }
    }

    if (!found_attribute) {
      throw error("campo '" + attribute_name.substr(4) +
                      "' não declarado na estrutura '" + this->name.substr(4) +
                      "'",
                  this->line);
    }

    this->attributes[i].second->get_type();
  }

  return Type(TypeKind::NAMED, this->name);
};

// Construtores
StructAllocationNode::StructAllocationNode(
    int line, string name, vector<pair<string, ExpressionNode*>> attributes)
    : ExpressionNode(line, name), attributes(attributes) {};
