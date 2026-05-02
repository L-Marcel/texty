#pragma once
#include "subprograms/procedure.hpp"

typedef unordered_map<string, Reference*> Scope;

struct References {
  vector<Scope> scopes;

  void push_scope();
  void pop_scope();

  Reference* get_reference(string name);

  static References* _instance;
  static References* get_instance();
  References();
};

// TODO: Registrar métodos e procedures nativos