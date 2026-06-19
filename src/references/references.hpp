#pragma once
#include "../nodes/access/access.hpp"
#include "subprograms/procedure.hpp"

typedef unordered_map<string, Reference*> Scope;

struct References {
  vector<Scope> scopes;
  Type subprogam_return_type;
  bool main_is_procedure;
  bool completed_return;

  Scope& get_scope();
  void push_scope();
  void pop_scope();
  size_t get_scope_level();
  string get_scope_ident();

  Type get_suprogram_return_type();
  void set_subprogram_return_type(Type type);
  void clear_subprogram_return_type();

  void set_main_is_procedure(bool main_is_procedure);
  bool get_main_is_procedure();

  bool has_reference(string name, ReferenceType reference_type);
  bool has_reference_in_current_scope(string name, ReferenceType reference_type);
  Reference* get_reference(int line, string name);
  string add_variable_reference(string name, Type type, bool is_const, bool generate_suffix = true);
  void add_procedure_reference(string name, vector<Type> params, bool self,
                               bool implemented);
  void add_function_reference(string name, Type type, vector<Type> params,
                              bool self, bool implemented);
  void initialize();

  unordered_map<string, vector<pair<string, Type>>> structs;
  void add_struct_reference(string name, vector<pair<string, Type>> attributes);
  vector<pair<string, Type>> get_struct_reference(string name);

  static References* _instance;
  static References* get_instance();
  References();
};