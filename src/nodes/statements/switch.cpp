#include "switch.hpp"

// Debug
void SwitchNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "SWITCH");
  Compiler::add_dot_relation(os, this, this->expression);
  for (size_t i = 0; i < this->cases.size(); i++) {
    Compiler::add_dot_relation(os, this, this->cases[i]);
  };
};

// Código
void SwitchNode::compile_code(ostream& os) const {
  // TODO
};

// Tipagem
Type SwitchNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
SwitchNode::SwitchNode(int line, ExpressionNode* expression,
                       vector<CaseNode*> cases)
    : Node(line), expression(expression), cases(cases) {};
