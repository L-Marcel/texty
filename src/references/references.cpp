#include <references.h>

void References::push_scope() { this->scopes.push_back(Scope()); };
void References::pop_scope() { this->scopes.pop_back(); };

void References::declare_var(string name, NodeType type) {};
void References::declare_function(string name) {};
void References::declare_subprogram(string name) {};

Reference* References::get_reference(string name) {
  for (int i = this->scopes.size() - 1; i >= 0; i--) {
    Scope& scope = this->scopes[i];
    Scope::iterator iterator = scope.find(name);
    if (iterator != scope.end()) {
      return iterator->second;
    }
  }

  return nullptr;
};