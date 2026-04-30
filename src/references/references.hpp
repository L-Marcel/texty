#pragma once
#include <string>
#include <unordered_map>
#include <vector>

#include "../debug/debug.hpp"
#include "../syntax/tree.h"

using namespace std;

enum class ReferenceType { VARIABLE, ENUM, STRUCT, TRAIT, FUNCTION, PROCEDURE };

struct Reference {
  int offset;
  NodeType node_type;
  ReferenceType reference_type;
  Node* node;

  virtual ~Reference() = default;

 protected:
  Reference(int offset, NodeType node_type, ReferenceType reference_type)
      : offset(offset), node_type(node_type), reference_type(reference_type) {};
};

typedef unordered_map<string, Reference*> Scope;

struct References {
  vector<Scope> scopes;

  void push_scope();
  void pop_scope();
  void declare(string name, NodeType node_type, ReferenceType reference_type);
  Reference* get_reference(string name);

  static References* _instance;
  static References* get_instance();
  References();
};

struct VariableReference : public Reference {
  VariableReference(int offset, NodeType node_type)
      : Reference(offset, node_type, ReferenceType::VARIABLE) {};
};

struct FunctionReference : public Reference {
  FunctionReference(int offset, NodeType node_type)
      : Reference(offset, node_type, ReferenceType::FUNCTION) {};
};

struct ProcedureReference : public Reference {
  ProcedureReference(int offset)
      : Reference(offset, NodeType::VOID, ReferenceType::PROCEDURE) {};
};
