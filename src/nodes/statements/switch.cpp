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

// Cobertura do retorno
ReturnCoverage SwitchNode::get_return_coverage() const {
  if (this->cases.empty()) return ReturnCoverage::NONE;

  bool has_default = false;
  bool all_guaranteed = true;
  bool any_return = false;

  for (size_t i = 0; i < this->cases.size(); i++) {
    CaseNode* current_case = this->cases[i];
    
    if (current_case->type == CaseType::DEFAULT) {
      has_default = true;
    };

    ReturnCoverage coverage = current_case->get_return_coverage();

    if (coverage != ReturnCoverage::GUARANTEED) {
      all_guaranteed = false;
    };
    
    if (coverage != ReturnCoverage::NONE) {
      any_return = true;
    };
  };

  if (all_guaranteed && has_default) {
    return ReturnCoverage::GUARANTEED;
  } else if (any_return) {
    return ReturnCoverage::PARTIAL;
  };

  return ReturnCoverage::NONE;
};

// Construtores
SwitchNode::SwitchNode(int line, ExpressionNode* expression,
                       vector<CaseNode*> cases)
    : Node(line), expression(expression), cases(cases) {};
