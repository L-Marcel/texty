#include "function.hpp"

#include "../../references/references.hpp"

// Debug
void FunctionNode::compile_dot(ostream& os) const {
  string params = params_to_string(this->params, false);
  Compiler::add_dot_node(
      os, this, "FUNCTION: " + this->name.substr(4) + "(" + params + ")");

  for (size_t i = 0; i < this->children.size(); i++) {
    Compiler::add_dot_relation(os, this, this->children[i]);
  };
};

// Código
void FunctionNode::compile_code(ostream& os) const {
  vector<Type> types = vector<Type>();
  for (size_t i = 0; i < this->params.size(); i++) {
    types.push_back(this->params[i].second);
  };

  References* references = References::get_instance();
  references->add_function_reference(this->name, this->type, types, this->self,
                                     this->implemented);

  if (this->implemented) {
    os << std::endl;

    ReturnCoverage coverage = this->get_return_coverage();
    if (coverage == ReturnCoverage::PARTIAL)
      throw error("função sem retorno garantido");
    else if (coverage == ReturnCoverage::NONE)
      throw error("função sem retorno");

    string params = params_to_string(this->params, true);
    os << this->type.to_production() << " " << this->name << "(" << params
       << ") {" << std::endl;

    references->push_scope();
    references->set_subprogram_return_type(this->get_type());
    for (size_t i = 0; i < this->params.size(); i++) {
      references->add_variable_reference(this->params[i].first,
                                         this->params[i].second, false);
    };

    string ident = references->get_scope_ident();
    for (size_t i = 0; i < this->children.size(); i++) {
      os << ident;
      this->children[i]->compile_code(os);
      os << ";" << std::endl;
    };

    references->pop_scope();
    references->clear_subprogram_return_type();
    os << "};" << std::endl;

    if (this->name == "txy_main") {
      os << "\nint main(" << params << ") {" << std::endl;
      string params = params_ids_to_string(this->params, true);
      os << "\treturn txy_main(" << params << ");" << std::endl;
      os << "};" << std::endl;
    };
  };
};

// Tipagem
Type FunctionNode::get_type() const { return this->type; };

// Construtores
FunctionNode::FunctionNode(int line, string name, Type type,
                           vector<pair<string, Type>> params, bool self,
                           bool implemented)
    : SubprogramNode(line, name, params, self, implemented), type(type) {};
