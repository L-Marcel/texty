#include "switch.hpp"
#include "../../references/references.hpp"

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
  string end_label = Compiler::get_next_label("switch_end");
  string default_label = Compiler::get_next_label("switch_default");
  string switch_expr_name = Compiler::get_next_label("switch_expr");

  References* references = References::get_instance();
  string current_continue = references->get_continue_label();
  references->push_loop(current_continue, end_label);

  Type expr_type = this->expression->get_type();
  os << expr_type.to_production() << " " << switch_expr_name << " = ";
  this->expression->compile_code(os);
  os << ";" << endl;

  string original_ident = references->get_scope_ident();

  bool has_default = false;

  for (size_t i = 0; i < this->cases.size(); i++) {
    CaseNode* case_node = this->cases[i];
    string case_label = Compiler::get_next_label("switch_case");

    case_node->label = case_label;

    if (case_node->type == CaseType::DEFAULT) {
      has_default = true;
    } else {
      for (size_t j = 0; j < case_node->expressions.size(); j++) {
        Type case_expr_type = case_node->expressions[j]->get_type();
        if (expr_type != case_expr_type) {
          throw error("tipo do caso (" + case_expr_type.to_string() + ") não compatível com tipo do switch (" + expr_type.to_string() + ")", case_node->line);
        };

        os << original_ident << "if (" << switch_expr_name << " == (";
        case_node->expressions[j]->compile_code(os);
        os << ")) goto " << case_label << ";" << endl;
      };
    };
  };

  if (has_default) {
    os << original_ident << "goto " << default_label << ";" << endl;
  } else {
    os << original_ident << "goto " << end_label << ";" << endl;
  };

  references->push_scope();
  string switch_ident = references->get_scope_ident();

  for (size_t i = 0; i < this->cases.size(); i++) {
    CaseNode* case_node = this->cases[i];

    if (case_node->type == CaseType::DEFAULT) {
      os << switch_ident << default_label << ":" << endl;
    } else {
      os << switch_ident << case_node->label << ":" << endl;
    };
    
    case_node->compile_code(os);
    os << switch_ident << "\t" << "goto " << end_label << ";" << endl;
  };

  references->pop_scope();
  os << original_ident << end_label << ":";

  references->pop_loop();
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
