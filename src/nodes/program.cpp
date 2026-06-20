#include "program.hpp"

#include "../lib/magic_enum.hpp"
#include "../references/references.hpp"
#include "compiler.hpp"
#include "structures/struct.hpp"

// Extração de estruturas e suas dependências
StructNode* get_struct_node(const vector<Node*>& children, string name) {
  for (size_t i = 0; i < children.size(); i++) {
    if (StructNode* sn = dynamic_cast<StructNode*>(children[i])) {
      if (sn->name == name) return sn;
    }
  };

  return nullptr;
};

void visit_node(Node* node, const vector<Node*>& children,
                unordered_set<Node*>& visited, unordered_set<Node*>& visiting,
                vector<Node*>& sorted_children) {
  if (visited.count(node)) return;
  if (visiting.count(node)) return;
  visiting.insert(node);

  if (StructNode* struct_node = dynamic_cast<StructNode*>(node)) {
    for (auto& attr : struct_node->attributes) {
      if (attr.second.kind == TypeKind::NAMED) {
        StructNode* dependency_struct_node =
            get_struct_node(children, attr.second.get_name());
        if (dependency_struct_node)
          visit_node(dependency_struct_node, children, visited, visiting,
                     sorted_children);
      };
    };
  };

  visiting.erase(node);
  visited.insert(node);
  sorted_children.push_back(node);
};

// Debug
void ProgramNode::compile_dot(ostream& os) const {
  if (this->name == "")
    Compiler::add_dot_node(
        os, this, string(magic_enum::enum_name(this->get_type().kind)));
  else
    Compiler::add_dot_node(os, this, this->name);

  for (size_t i = 0; i < this->children.size(); i++) {
    Compiler::add_dot_relation(os, this, this->children[i]);
  };
};

// Código
void ProgramNode::compile_code(ostream& os) const {
  References::get_instance()->push_scope();
  References::get_instance()->initialize();

  for (size_t i = 0; i < this->children.size(); i++) {
    if (StructNode* struct_node =
            dynamic_cast<StructNode*>(this->children[i])) {
      References::get_instance()->add_struct_reference(struct_node->line, struct_node->name,
                                                       struct_node->attributes);
      generated_declarations << "typedef struct " << struct_node->name << " "
                             << struct_node->name << ";" << std::endl;
      generated_declarations << "int " << struct_node->name << "_compare("
                             << struct_node->name << " a, " << struct_node->name
                             << " b);" << std::endl;
      generated_declarations << "char* " << struct_node->name << "_to_string("
                             << struct_node->name << " instance);" << std::endl;
      generated_declarations << struct_node->name << " " << struct_node->name
                             << "_default();" << std::endl;
    }
  };

  vector<Node*> sorted_children;
  unordered_set<Node*> visited;
  unordered_set<Node*> visiting;

  for (size_t i = 0; i < this->children.size(); i++) {
    visit_node(this->children[i], this->children, visited, visiting,
               sorted_children);
  };

  for (size_t i = 0; i < sorted_children.size(); i++) {
    sorted_children[i]->compile_code(os);
  };

  bool has_main_as_procedure = References::get_instance()->has_reference(
      "txy_main", ReferenceType::PROCEDURE);
  bool has_main_as_function = References::get_instance()->has_reference(
      "txy_main", ReferenceType::FUNCTION);

  if (!has_main_as_function && !has_main_as_procedure) {
    throw error("subprograma main não declarado");
  }

  References::get_instance()->pop_scope();
};

// Tipagem
Type ProgramNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
ProgramNode::ProgramNode(int line) : Node(line, "PROGRAM") {};
