#include <string>
#include <unordered_map>
#include <vector>

#include "../syntax/tree.h"

using namespace std;

enum ReferenceType { VARIABLE, FUNCTION, PROCEDURE };

struct Reference {
  int offset;
  ReferenceType type;
  Node* node;

  virtual ~Reference() = default;

 protected:
  Reference(int offset, ReferenceType type) : offset(offset), type(type) {};
};

typedef unordered_map<string, Reference*> Scope;

struct References {
  vector<Scope> scopes;
  void push_scope();
  void pop_scope();
  void declare_var(string name, NodeType type);
  void declare_function(string name);
  void declare_subprogram(string name);
  Reference* get_reference(string name);
};

struct VariableReference : public Reference {
  VariableReference(int offset) : Reference(offset, ReferenceType::VARIABLE) {};
};

struct FunctionReference : public Reference {
  FunctionReference(int offset) : Reference(offset, ReferenceType::FUNCTION) {};
};

struct ProcedureReference : public Reference {
  ProcedureReference(int offset)
      : Reference(offset, ReferenceType::PROCEDURE) {};
};
