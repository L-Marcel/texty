#include "for.hpp"

#include "../../references/references.hpp"
#include "../compiler.hpp"

// Debug
void ForNode::compile_dot(ostream& os) const {
  switch (this->type) {
    case ForType::SINGLE_EXPRESSION:
      Compiler::add_dot_node(os, this, "FOR: " + this->name.substr(4));
      Compiler::add_dot_relation(os, this, this->expression);
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children[i]);
      };
      break;
    case ForType::THREE_EXPRESSION:
      Compiler::add_dot_node(os, this, "FOR");
      Compiler::add_dot_relation(os, this, this->attr);
      Compiler::add_dot_relation(os, this, this->condition);
      Compiler::add_dot_relation(os, this, this->increment);
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children[i]);
      };
      break;
  }
};

// Código
void ForNode::compile_code(ostream& os) const {
  References* references = References::get_instance();
  string start_label = Compiler::get_next_label("for_start");
  string body_label = Compiler::get_next_label("for_body");
  string inc_label = Compiler::get_next_label("for_increment");
  string end_label = Compiler::get_next_label("for_end");

  references->push_loop(inc_label, end_label);

  switch (this->type) {
    case ForType::SINGLE_EXPRESSION: {
      Type expr_type = this->expression->get_type();
      if (expr_type.kind != TypeKind::ARRAY &&
          expr_type.kind != TypeKind::RANGE) {
        throw error(
            "estrutura de repetição 'for' espera um (array<unknown>), "
            "(range<int>), (range<byte>) ou (range<long>) mas "
            "recebeu (" +
                expr_type.to_string() + ")",
            this->line);
      };

      if (expr_type.kind == TypeKind::RANGE) {
        if (expr_type.inner_type->kind != TypeKind::INT &&
            expr_type.inner_type->kind != TypeKind::BYTE &&
            expr_type.inner_type->kind != TypeKind::LONG) {
          throw error(
              "estrutura de repetição 'for' espera um (array<unknown>), "
              "(range<int>), (range<byte>) ou (range<long>) mas "
              "recebeu (" +
                  expr_type.to_string() + ")",
              this->line);
        };
      };

      string ident_outer = references->get_scope_ident();
      string temp_expr = Compiler::get_next_label("txy_expr");
      string temp_idx = Compiler::get_next_label("txy_idx");
      string temp_end = Compiler::get_next_label("txy_end");

      os << expr_type.to_production() << " " << temp_expr << " = ";
      this->expression->compile_code(os);
      os << ";" << std::endl;

      if (expr_type.kind == TypeKind::ARRAY) {
        os << ident_outer << "int " << temp_idx << " = 0;" << std::endl;
        os << ident_outer << "int " << temp_end << " = " << temp_expr
           << ".capacity;" << std::endl;
      } else {
        string v_field;
        if (expr_type.inner_type->kind == TypeKind::INT)
          v_field = "v_int";
        else if (expr_type.inner_type->kind == TypeKind::BYTE)
          v_field = "v_byte";
        else if (expr_type.inner_type->kind == TypeKind::LONG)
          v_field = "v_long";

        os << ident_outer << expr_type.inner_type->to_production() << " "
           << temp_idx << " = " << temp_expr << ".left.value." << v_field << ";"
           << std::endl;
        os << ident_outer << "if (!" << temp_expr << ".left_inclusive) "
           << temp_idx << " = " << temp_idx << " + 1;" << std::endl;
        os << ident_outer << expr_type.inner_type->to_production() << " "
           << temp_end << " = " << temp_expr << ".right.value." << v_field
           << ";" << std::endl;
        os << ident_outer << "if (!" << temp_expr << ".right_inclusive) "
           << temp_end << " = " << temp_end << " - 1;" << std::endl;
      };

      os << start_label << ":;" << std::endl;
      if (expr_type.kind == TypeKind::ARRAY) {
        os << ident_outer << "if (" << temp_idx << " < " << temp_end
           << ") goto " << body_label << ";" << std::endl;
      } else {
        os << ident_outer << "if (" << temp_idx << " <= " << temp_end
           << ") goto " << body_label << ";" << std::endl;
      };
      os << ident_outer << "goto " << end_label << ";" << std::endl;

      references->push_scope();
      string ident = references->get_scope_ident();
      os << body_label << ":;" << std::endl;

      if (references->has_reference_in_current_scope(this->name,
                                                     ReferenceType::VARIABLE)) {
        throw error("variável '" + this->name.substr(4) +
                        "' já foi declarada neste escopo",
                    this->line);
      };

      string name_suffix = references->add_variable_reference(
          this->name, *expr_type.inner_type, true);

      if (expr_type.kind == TypeKind::ARRAY) {
        os << ident << expr_type.inner_type->to_production() << " "
           << this->name << name_suffix << " = " << temp_expr << ".pointer["
           << temp_idx << "];" << std::endl;
      } else {
        os << ident << expr_type.inner_type->to_production() << " "
           << this->name << name_suffix << " = " << temp_idx << ";"
           << std::endl;
      };

      for (size_t i = 0; i < this->children.size(); i++) {
        os << ident;
        this->children[i]->compile_code(os);
        os << ";" << std::endl;
      };

      references->pop_scope();

      os << inc_label << ":;" << std::endl;
      os << ident_outer << temp_idx << " = " << temp_idx << " + 1;"
         << std::endl;
      os << ident_outer << "goto " << start_label << ";" << std::endl;

      os << end_label << ":;";
      break;
    };
    case ForType::THREE_EXPRESSION: {
      string ident_outer = references->get_scope_ident();

      references->push_scope();
      string ident = references->get_scope_ident();

      if (this->attr) {
        this->attr->compile_code(os);
        os << ";" << std::endl;
      };

      os << start_label << ":;" << std::endl;
      os << ident;
      if (this->condition) {
        Type cond_type = this->condition->get_type();
        if (cond_type != Type(TypeKind::BOOL)) {
          throw error(
              "estrutura de repetição espera uma condição do tipo (bool) mas "
              "recebeu (" +
                  cond_type.to_string() + ")",
              this->line);
        }
        os << "if (";
        this->condition->compile_code(os);
        os << ") goto " << body_label << ";" << std::endl;
      } else {
        os << "goto " << body_label << ";" << std::endl;
      };
      os << ident << "goto " << end_label << ";" << std::endl;

      os << body_label << ":;" << std::endl;
      for (size_t i = 0; i < this->children.size(); i++) {
        os << ident;
        this->children[i]->compile_code(os);
        os << ";" << std::endl;
      };

      os << inc_label << ":;" << std::endl;
      if (this->increment) {
        os << ident;
        this->increment->compile_code(os);
        os << ";" << std::endl;
      };
      os << ident << "goto " << start_label << ";" << std::endl;

      references->pop_scope();

      os << end_label << ":;";
      break;
    };
  };

  references->pop_loop();
};

// Tipagem
Type ForNode::get_type() const { return Type(TypeKind::VOID); };

// Cobertura dos retornos
ReturnCoverage ForNode::get_return_coverage() const {
  ReturnCoverage block_coverage = ReturnCoverage::NONE;

  for (size_t i = 0; i < this->children.size(); i++) {
    ReturnCoverage coverage = this->children[i]->get_return_coverage();

    if (coverage == ReturnCoverage::GUARANTEED) {
      block_coverage = ReturnCoverage::PARTIAL;

      if (i + 1 < this->children.size()) {
        throw error("código inalcançável detectado após instrução de retorno",
                    this->children[i + 1]->line);
      };

      break;
    } else if (coverage == ReturnCoverage::PARTIAL) {
      block_coverage = ReturnCoverage::PARTIAL;
    };
  };

  return block_coverage;
};

// Construtores
ForNode::ForNode(int line, string name, ExpressionNode* expression)
    : Node(line, name),
      type(ForType::SINGLE_EXPRESSION),
      expression(expression) {};
ForNode::ForNode(int line, AttrNode* attr, ExpressionNode* condition,
                 ExpressionNode* increment)
    : Node(line),
      type(ForType::THREE_EXPRESSION),
      attr(attr),
      condition(condition),
      increment(increment) {};