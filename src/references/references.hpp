#pragma once
#include "../nodes/access/access.hpp"
#include "subprograms/procedure.hpp"

typedef unordered_map<string, Reference*> Scope;

struct References {
  vector<Scope> scopes;

  Scope& get_scope();
  void push_scope();
  void pop_scope();

  bool has_reference(string name, ReferenceType reference_type);
  Reference* get_reference(int line, string name);
  void add_variable_reference(string name, Type type, bool is_const);
  void add_procedure_reference(string name, vector<Type> params, bool self,
                               bool implemented);
  void add_function_reference(string name, Type type, vector<Type> params,
                              bool self, bool implemented);

  static References* _instance;
  static References* get_instance();
  References();
};

// TODO: Registrar métodos e procedures nativos