#include "subprogram.hpp"

#include "../../references/references.hpp"

// Params
string params_to_string(vector<pair<string, Type>> params, bool production) {
  string text = "";

  if (production) {
    for (size_t i = 0; i < params.size(); i++) {
      text += params[i].second.to_production() + " " + params[i].first;
      if (i != params.size() - 1) {
        text += ", ";
      };
    };
  } else {
    for (size_t i = 0; i < params.size(); i++) {
      text += params[i].first.substr(4) + ": " + params[i].second.to_string();
      if (i != params.size() - 1) {
        text += ", ";
      };
    };
  };

  return text;
};

string params_ids_to_string(vector<pair<string, Type>> params,
                            bool production) {
  string text = "";

  for (size_t i = 0; i < params.size(); i++) {
    if (production) {
      text += params[i].first;
    } else {
      text += params[i].first.substr(4);
    };
    
    if (i != params.size() - 1) {
      text += ", ";
    };
  };

  return text;
};

// Debug
void SubprogramNode::compile_dot(ostream& os) const {
  string params = params_to_string(this->params, false);
  Compiler::add_dot_node(os, this,
                         "SUBPROGRAM: " + this->name.substr(4) + "(" + params + ")");

  for (size_t i = 0; i < this->children.size(); i++) {
    Compiler::add_dot_relation(os, this, this->children[i]);
  };
};

// Código
void SubprogramNode::compile_code(ostream& os) const {};

// Tipagem
Type SubprogramNode::get_type() const {
  for (size_t i = 0; i < this->children.size(); i++) {
    this->children[i]->get_type();
  };

  return Type(TypeKind::UNKNOWN);
};

// Construtores
SubprogramNode::SubprogramNode(int line, string name,
                               vector<pair<string, Type>> params, bool self,
                               bool implemented)
    : Node(line, name), params(params), self(self), implemented(implemented) {};