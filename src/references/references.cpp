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
void References::add_struct_reference(int line, string name,
                                      vector<pair<string, Type>> attributes) {
  if (this->enums.find(name) != this->enums.end()) {
    if (line != -1) throw error("tipo '" + name.substr(4) + "' já declarado como enumeração", line);
  }
  if (this->structs.find(name) != this->structs.end()) {
    if (line != -1) throw error("estrutura '" + name.substr(4) + "' já declarada", line);
  }
  this->structs[name] = attributes;
};
bool References::has_struct_reference(string name) {
  return this->structs.find(name) != this->structs.end();
};
vector<pair<string, Type>> References::get_struct_reference(string name) {
  if (this->structs.find(name) != this->structs.end()) {
    return this->structs[name];
  };

  return {};
};

// Enums
void References::add_enum_reference(int line, string name,
                                    vector<string> values) {
  if (this->structs.find(name) != this->structs.end()) {
    if (line != -1) throw error("tipo '" + name.substr(4) + "' já declarado como estrutura", line);
  }
  if (this->enums.find(name) != this->enums.end()) {
    if (line != -1) throw error("enumeração '" + name.substr(4) + "' já declarada", line);
  }

  unordered_set<string> declared_values;
  for (size_t i = 0; i < values.size(); i++) {
    if (declared_values.find(values[i]) != declared_values.end()) {
      if (line != -1) {
        throw error("valor '" + values[i].substr(4) +
                        "' já declarado na enumeração '" + name.substr(4) + "'",
                    line);
      }
    }
    declared_values.insert(values[i]);
  }

  this->enums[name] = values;
};
bool References::has_enum_reference(string name) {
  return this->enums.find(name) != this->enums.end();
};
bool References::has_enum_value(string enum_name, string value_name) {
  vector<string> values = this->get_enum_reference(enum_name);
  for (size_t i = 0; i < values.size(); i++) {
    if (values[i] == value_name) return true;
  }
  return false;
};
vector<string> References::get_enum_reference(string name) {
  if (this->enums.find(name) != this->enums.end()) {
    return this->enums[name];
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

// Laços de repetição
void References::push_loop(string continue_label, string break_label) {
  this->loop_labels.push_back({continue_label, break_label});
};
void References::pop_loop() { this->loop_labels.pop_back(); };
string References::get_continue_label() {
  if (this->loop_labels.empty()) return "";
  return this->loop_labels.back().first;
};
string References::get_break_label() {
  if (this->loop_labels.empty()) return "";
  return this->loop_labels.back().second;
};

// Tipo de retorno
Type References::get_suprogram_return_type() {
  return this->subprogam_return_type;
};
void References::set_subprogram_return_type(Type type) {
  this->subprogam_return_type = Type(type);
};
void References::clear_subprogram_return_type() {
  this->subprogam_return_type = Type(TypeKind::UNKNOWN);
};

// Caso main seja um procedimento
void References::set_main_is_procedure(bool main_is_procedure) {
  this->main_is_procedure = main_is_procedure;
};
bool References::get_main_is_procedure() { return this->main_is_procedure; };

// Referências
static int variable_suffix_counter = 0;

string References::add_variable_reference(string name, Type type, bool is_const,
                                          bool generate_suffix) {
  string name_suffix = "";
  if (generate_suffix) {
    name_suffix = "_" + to_string(++variable_suffix_counter);
  }
  this->get_scope().insert(
      {name, new VariableReference(type, is_const, name_suffix)});
  return name_suffix;
};
void References::add_procedure_reference(int line, string name, vector<Type> params,
                                         bool self, bool implemented) {
  Scope& scope = this->get_scope();
  if (scope.find(name) != scope.end()) {
    Reference* existing = scope[name];
    if (existing->reference_type == ReferenceType::PROCEDURE) {
        ProcedureReference* p_ref = dynamic_cast<ProcedureReference*>(existing);
        if (!p_ref->implemented && implemented) {
            p_ref->implemented = true;
            return;
        }
    }
    if (line != -1) throw error("subprograma ou variável '" + name.substr(4) + "' já declarada neste escopo", line);
  }
  scope.insert({name, new ProcedureReference(params, self, implemented)});
};
void References::add_function_reference(int line, string name, Type type,
                                        vector<Type> params, bool self,
                                        bool implemented) {
  Scope& scope = this->get_scope();
  if (scope.find(name) != scope.end()) {
    Reference* existing = scope[name];
    if (existing->reference_type == ReferenceType::FUNCTION) {
        FunctionReference* f_ref = dynamic_cast<FunctionReference*>(existing);
        if (!f_ref->implemented && implemented) {
            f_ref->implemented = true;
            return;
        }
    }
    if (line != -1) throw error("subprograma ou variável '" + name.substr(4) + "' já declarada neste escopo", line);
  }
  scope.insert({name, new FunctionReference(type, params, self, implemented)});
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

bool References::has_reference_in_current_scope(string name,
                                                ReferenceType reference_type) {
  if (this->scopes.empty()) return false;
  Scope& scope = this->get_scope();
  Scope::iterator scope_iterator = scope.find(name);
  if (scope_iterator != scope.end() &&
      scope_iterator->second->reference_type == reference_type) {
    return true;
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
  this->add_procedure_reference(-1, "txy_print", {Type(TypeKind::STRING)}, false,
                                true);
  this->add_procedure_reference(-1, "txy_println", {Type(TypeKind::STRING)}, false,
                                true);
  this->add_function_reference(-1, "txy_format", Type(TypeKind::STRING), {}, false,
                               true);
  this->add_function_reference(-1, "txy_join", Type(TypeKind::STRING), {}, false,
                               true);
  this->add_function_reference(-1, "txy_key_pressed", Type(TypeKind::INT), {},
                               false, false);
  this->add_function_reference(-1, "txy_input_line", Type(TypeKind::STRING), {},
                               false, false);

  Type types[] = {Type(TypeKind::BOOL),   Type(TypeKind::CHAR),
                  Type(TypeKind::BYTE),   Type(TypeKind::INT),
                  Type(TypeKind::LONG),   Type(TypeKind::FLOAT),
                  Type(TypeKind::DOUBLE), Type(TypeKind::STRING)};

  for (const Type& to : types) {
    this->add_function_reference(-1, "txy_" + to.get_name(), to, {}, false, true);
  };

  // TODO: Registrar métodos e procedures nativos
};
