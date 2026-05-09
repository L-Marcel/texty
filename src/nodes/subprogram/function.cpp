#include "function.hpp"

#include "../../references/references.hpp"

// Params
string params_to_string(vector<Param> params) {
  string text = "";
  for (size_t i = 0; i < params.size(); i++) {
    string id = params[i].first;
    Type type = params[i].second;
    text += id + ": " + type.to_string();
    if (i != params.size() - 1) {
      text += ", ";
    };
  };

  return text;
};

// Debug
void FunctionNode::compile_dot(ostream& os) const {
  string params = params_to_string(this->params);
  Compiler::add_dot_node(os, this,
                         "FUNCTION: " + this->name + "(" + params + ")");

  for (size_t i = 0; i < this->children.size(); i++) {
    Compiler::add_dot_relation(os, this, this->children.at(i));
  };
}

// Código
void FunctionNode::compile_code(ostream& os) const {
  vector<Type> types = vector<Type>();
  for (size_t i = 0; i < this->params.size(); i++) {
    types.push_back(this->params[i].second);
  };

  References::get_instance()->add_function_reference(this->name, this->type,
                                                     types);
  References::get_instance()->push_scope();
  for (size_t i = 0; i < this->children.size(); i++) {
    this->children.at(i)->compile_code(os);
  };
  References::get_instance()->pop_scope();
}

// Tipagem
Type FunctionNode::get_type() const { return this->type; };

// Construtores
FunctionNode::FunctionNode(int line, string name, Type type,
                           vector<pair<string, Type>> params)
    : Node(line, name), type(type), params(params) {};