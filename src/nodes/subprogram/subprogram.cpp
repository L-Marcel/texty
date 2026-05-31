#include "subprogram.hpp"

#include "../../references/references.hpp"

// Params
string params_to_string(vector<pair<string, Type>> params) {
  string text = "";
  for (size_t i = 0; i < params.size(); i++) {
    text += params[i].first + ": " + params[i].second.to_string();
    if (i != params.size() - 1) {
      text += ", ";
    };
  };

  return text;
};

// Debug
void SubprogramNode::compile_dot(ostream& os) const {
  string params = params_to_string(this->params);
  Compiler::add_dot_node(os, this,
                         "SUBPROGRAM: " + this->name + "(" + params + ")");

  for (size_t i = 0; i < this->children.size(); i++) {
    Compiler::add_dot_relation(os, this, this->children.at(i));
  };
};

// Código
void SubprogramNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type SubprogramNode::get_type() const {
  for (size_t i = 0; i < this->children.size(); i++) {
    this->children.at(i)->get_type();
  };

  return Type(TypeKind::UNKNOWN);
};

// Construtores
SubprogramNode::SubprogramNode(int line, string name,
                               vector<pair<string, Type>> params)
    : Node(line, name), params(params) {};
SubprogramNode::SubprogramNode(int line, string name,
                               vector<pair<string, Type>> params, bool self)
    : Node(line, name), params(params), self(self) {};