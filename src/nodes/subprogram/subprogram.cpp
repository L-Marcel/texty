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

string types_to_string(vector<Type> types, bool production) {
  string text = "";

  if (production) {
    for (size_t i = 0; i < types.size(); i++) {
      text += types[i].to_production();
      if (i != types.size() - 1) {
        text += ", ";
      };
    };
  } else {
    for (size_t i = 0; i < types.size(); i++) {
      text += types[i].to_string();
      if (i != types.size() - 1) {
        text += ", ";
      };
    };
  };

  return text;
};

string expressions_types_to_string(vector<ExpressionNode*> expressions,
                                   bool production) {
  string text = "";

  if (production) {
    for (size_t i = 0; i < expressions.size(); i++) {
      text += expressions[i]->get_type().to_production();
      if (i != expressions.size() - 1) {
        text += ", ";
      };
    };
  } else {
    for (size_t i = 0; i < expressions.size(); i++) {
      text += expressions[i]->get_type().to_string();
      if (i != expressions.size() - 1) {
        text += ", ";
      };
    };
  };

  return text;
};

// Debug
void SubprogramNode::compile_dot(ostream& os) const {
  string params = params_to_string(this->params, false);
  Compiler::add_dot_node(
      os, this, "SUBPROGRAM: " + this->name.substr(4) + "(" + params + ")");

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


// Cobertura do retorno
ReturnCoverage SubprogramNode::get_return_coverage() const {
  if (!this->implemented) {
    return ReturnCoverage::NONE;
  };

  ReturnCoverage final_coverage = ReturnCoverage::NONE;

  for (size_t i = 0; i < this->children.size(); i++) {
    ReturnCoverage child_coverage = this->children[i]->get_return_coverage();

    if (child_coverage == ReturnCoverage::GUARANTEED) {
      final_coverage = ReturnCoverage::GUARANTEED;
      
      if (i + 1 < this->children.size()) {
        throw error("código inalcançável detectado após instrução de retorno", 
                    this->children[i + 1]->line);
      };

      break;
    } else if (child_coverage == ReturnCoverage::PARTIAL) {
      final_coverage = ReturnCoverage::PARTIAL;
    };
  };

  return final_coverage;
};

// Construtores
SubprogramNode::SubprogramNode(int line, string name,
                               vector<pair<string, Type>> params, bool self,
                               bool implemented)
    : Node(line, name), params(params), self(self), implemented(implemented) {};