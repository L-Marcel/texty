#include "procedure.hpp"

#include "../../references/references.hpp"

// Debug
void ProcedureNode::compile_dot(ostream& os) const {
  string params = params_to_string(this->params, false);
  Compiler::add_dot_node(
      os, this, "PROCEDURE: " + this->name.substr(4) + "(" + params + ")");

  for (size_t i = 0; i < this->children.size(); i++) {
    Compiler::add_dot_relation(os, this, this->children[i]);
  };
}

// Código
void ProcedureNode::compile_code(ostream& os) const {
  vector<Type> types = vector<Type>();
  for (size_t i = 0; i < this->params.size(); i++) {
    types.push_back(this->params[i].second);
  };

  References* references = References::get_instance();
  references->add_procedure_reference(this->line, this->name, types, this->self,
                                      this->implemented);

  if (this->implemented) {
    os << std::endl;

    this->get_return_coverage();

    string params = params_to_string(this->params, true);
    if (this->name == "txy_main") {
      os << "int " << this->name << "(" << params << ") {" << std::endl;

      references->push_scope();
      references->set_subprogram_return_type(this->get_type());
      references->set_main_is_procedure(true);
      for (size_t i = 0; i < this->params.size(); i++) {
        references->add_variable_reference(this->params[i].first,
                                           this->params[i].second, false, false);
      };

      string ident = references->get_scope_ident();
      for (size_t i = 0; i < this->children.size(); i++) {
        os << ident;
        this->children[i]->compile_code(os);
        os << ";" << std::endl;
      };
      os << "\treturn 0;" << std::endl;
    } else {
      os << "void " << this->name << "(" << params << ") {" << std::endl;

      references->push_scope();
      references->set_subprogram_return_type(this->get_type());
      for (size_t i = 0; i < this->params.size(); i++) {
        references->add_variable_reference(this->params[i].first,
                                           this->params[i].second, false, false);
      };

      string ident = references->get_scope_ident();
      for (size_t i = 0; i < this->children.size(); i++) {
        os << ident;
        this->children[i]->compile_code(os);
        os << ";" << std::endl;
      };
    };

    references->pop_scope();
    references->clear_subprogram_return_type();
    references->set_main_is_procedure(false);
    os << "};" << std::endl;

    if (this->name == "txy_main") {
      os << std::endl << "int main(" << params << ") {" << std::endl;
      string params = params_ids_to_string(this->params, true);
      os << "\treturn txy_main(" << params << ");" << std::endl;
      os << "};" << std::endl;
    };
  };
};

// Tipagem
Type ProcedureNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
ProcedureNode::ProcedureNode(int line, string name,
                             vector<pair<string, Type>> params, bool self,
                             bool implemented)
    : SubprogramNode(line, name, params, self, implemented) {};