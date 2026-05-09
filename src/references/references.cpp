#include "references.hpp"

// Singleton
References::References() {};
References* References::_instance = nullptr;
References* References::get_instance() {
  if (References::_instance == nullptr) {
    References::_instance = new References();
  }

  return References::_instance;
};

// Escopo
void References::push_scope() { this->scopes.push_back(Scope()); };
void References::pop_scope() { this->scopes.pop_back(); };
Scope References::get_scope() const {
  return this->scopes.at(this->scopes.size() - 1);
};

// Referências
void References::add_variable_reference(string name, Type type, bool is_const) {
  this->get_scope().insert({name, new VariableReference(type, is_const)});
};
void References::add_procedure_reference(string name, vector<Type> params) {
  this->get_scope().insert({name, new ProcedureReference(params)});
};
void References::add_function_reference(string name, Type type,
                                        vector<Type> params) {
  this->get_scope().insert({name, new FunctionReference(type, params)});
};

Reference* References::get_reference(int line, string name) {
  for (size_t i = this->scopes.size() - 1; i >= 0; i--) {
    Scope& scope = this->scopes[i];
    Scope::iterator iterator = scope.find(name);
    if (iterator != scope.end()) {
      return iterator->second;
    }
  }

  throw error("tentativa inválida de acesso", line);
};