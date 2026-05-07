#include "function.hpp"

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
  // TODO
}

// Tipagem
Type FunctionNode::get_type() const {
  for (size_t i = 0; i < this->children.size(); i++) {
    this->children.at(i)->get_type();
  };

  return this->type;
};

// Construtores
FunctionNode::FunctionNode(int line, string name, Type type,
                           vector<pair<string, Type>> params)
    : Node(line, name), type(type), params(params) {};