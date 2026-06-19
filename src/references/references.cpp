#include "references.hpp"

#include "../helpers/string.hpp"

// Singleton
References::References() : subprogam_return_type(Type(TypeKind::UNKNOWN)) {};
References* References::_instance = nullptr;
References* References::get_instance() {
  if (References::_instance == nullptr) {
    References::_instance = new References();
  }
  return References::_instance;
};

// Structs
void References::add_struct_reference(string name,
                                      vector<pair<string, Type>> attributes) {
  this->structs[name] = attributes;
};
vector<pair<string, Type>> References::get_struct_reference(string name) {
  if (this->structs.find(name) != this->structs.end()) {
    return this->structs[name];
  };

  return {};
};

// Escopo
void References::push_scope() { this->scopes.push_back(Scope()); };
void References::pop_scope() { this->scopes.pop_back(); };
Scope& References::get_scope() { return this->scopes.back(); };
size_t References::get_scope_level() { return this->scopes.size(); };
string References::get_scope_ident() {
  size_t level = this->get_scope_level();
  if (level <= 1)
    return "";
  else
    return repeat("\t", level - 1);
};

// Tipo de retorno
Type References::get_suprogram_return_type() {
  return this->subprogam_return_type;
};
void References::set_subprogram_return_type(Type type) {
  this->subprogam_return_type = Type(type);
  this->declared_variables.clear();
};
void References::clear_subprogram_return_type() {
  this->subprogam_return_type = Type(TypeKind::UNKNOWN);
  this->declared_variables.clear();
};

bool References::declare_c_variable(string name) {
  if (this->declared_variables.find(name) != this->declared_variables.end()) {
    return false;
  }
  this->declared_variables.insert(name);
  return true;
};

// Caso main seja um procedimento
void References::set_main_is_procedure(bool main_is_procedure) {
  this->main_is_procedure = main_is_procedure;
};
bool References::get_main_is_procedure() { return this->main_is_procedure; };

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

  throw error("tentativa inválida de acesso a variável ou subprograma \'" +
                  name.substr(4) + "\' não declarado",
              line);
};

// Inicialização
void References::initialize() {
  this->add_procedure_reference("txy_print", {Type(TypeKind::STRING)}, false,
                                true);
  this->add_procedure_reference("txy_println", {Type(TypeKind::STRING)}, false,
                                true);
  this->add_function_reference("txy_format", Type(TypeKind::STRING), {}, false,
                               true);
  this->add_function_reference("txy_join", Type(TypeKind::STRING), {}, false,
                               true);
  this->add_function_reference("txy_key_pressed", Type(TypeKind::INT), {},
                               false, false);
  this->add_function_reference("txy_input_line", Type(TypeKind::STRING), {},
                               false, false);

  Type types[] = {Type(TypeKind::BOOL),   Type(TypeKind::CHAR),
                  Type(TypeKind::BYTE),   Type(TypeKind::INT),
                  Type(TypeKind::LONG),   Type(TypeKind::FLOAT),
                  Type(TypeKind::DOUBLE), Type(TypeKind::STRING)};

  for (const Type& to : types) {
    this->add_function_reference("txy_" + to.get_name(), to, {}, false, true);
  };

  // TODO: Registrar métodos e procedures nativos
};