#include "references.hpp"

References* References::_instance = nullptr;

References::References() {};
References* References::get_instance() {
  if (References::_instance == nullptr) {
    References::_instance = new References();
  }

  return References::_instance;
};

void References::push_scope() { this->scopes.push_back(Scope()); };
void References::pop_scope() { this->scopes.pop_back(); };

void References::declare(string name, NodeType type, ReferenceType reference) {
};

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