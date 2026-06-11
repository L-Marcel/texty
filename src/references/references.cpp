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
Scope& References::get_scope() { return this->scopes.back(); };

// Referências
void References::add_variable_reference(string name, Type type, bool is_const) {
  this->get_scope().insert({name, new VariableReference(type, is_const)});
};
void References::add_procedure_reference(string name, vector<Type> params,
                                         bool self, bool implemented) {
  this->get_scope().insert(
      {name, new ProcedureReference(params, self, implemented)});
};
void References::add_function_reference(string name, Type type,
                                        vector<Type> params, bool self,
                                        bool implemented) {
  this->get_scope().insert(
      {name, new FunctionReference(type, params, self, implemented)});
};

bool References::has_reference(string name, ReferenceType reference_type) {
  for (reverse_iterator iterator = this->scopes.rbegin();
       iterator != this->scopes.rend(); ++iterator) {
    Scope& scope = *iterator;
    Scope::iterator scope_iterator = scope.find(name);
    if (scope_iterator != scope.end() &&
        scope_iterator->second->reference_type == reference_type) {
      return true;
    }
  }

  return false;
};

Reference* References::get_reference(int line, string name) {
  for (reverse_iterator iterator = this->scopes.rbegin();
       iterator != this->scopes.rend(); ++iterator) {
    Scope& scope = *iterator;
    Scope::iterator scope_iterator = scope.find(name);
    if (scope_iterator != scope.end()) {
      return scope_iterator->second;
    }
  }

  throw error(
      "tentativa inválida de acesso a variável ou subprograma não declarado",
      line);
};