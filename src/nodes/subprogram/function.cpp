#include "function.hpp"

#include "../../references/references.hpp"

// Debug
void FunctionNode::compile_dot(ostream& os) const {
  string params = params_to_string(this->params, false);
  Compiler::add_dot_node(os, this,
                         "FUNCTION: " + this->name + "(" + params + ")");

  for (size_t i = 0; i < this->children.size(); i++) {
    Compiler::add_dot_relation(os, this, this->children[i]);
  };
};

// Código
void FunctionNode::compile_code(ostream& os) const {
  // TODO
  // vector<Type> types = vector<Type>();
  // for (size_t i = 0; i < this->params.size(); i++) {
  //   types.push_back(this->params[i].second);
  // };

  // References::get_instance()->add_function_reference(this->name, this->type,
  //                                                    types);
  // References::get_instance()->push_scope();
  // for (size_t i = 0; i < this->children.size(); i++) {
  //   this->children[i]->compile_code(os);
  // };
  // References::get_instance()->pop_scope();
};

// Tipagem
Type FunctionNode::get_type() const { return this->type; };

// Construtores
FunctionNode::FunctionNode(int line, string name, Type type,
                           vector<pair<string, Type>> params, bool self,
                           bool implemented)
    : SubprogramNode(line, name, params, self, implemented), type(type) {};