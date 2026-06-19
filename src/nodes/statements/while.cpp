#include "while.hpp"

#include "../../references/references.hpp"
#include "../compiler.hpp"

// Debug
void WhileNode::compile_dot(ostream& os) const {
  switch (this->type) {
    case WhileType::WHILE:
      Compiler::add_dot_node(os, this, "WHILE");
      Compiler::add_dot_relation(os, this, this->condition);
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children[i]);
      };
      break;
    case WhileType::REPEAT:
      Compiler::add_dot_node(os, this, "REPEAT");
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children[i]);
      };
      Compiler::add_dot_relation(os, this, this->condition);
      break;
  }
};

// Código
void WhileNode::compile_code(ostream& os) const {
  References* references = References::get_instance();
  string start_label = Compiler::get_next_label("while_start");
  string body_label = Compiler::get_next_label("while_body");
  string cond_label = Compiler::get_next_label("while_cond");
  string end_label = Compiler::get_next_label("while_end");

  Type type = this->condition->get_type();
  if (type != Type(TypeKind::BOOL) && this->type == WhileType::WHILE) {
    throw error(
        "estrutura de repetição 'while' espera uma condição do tipo (bool) "
        "mas recebeu (" +
            type.to_string() + ")",
        this->line);
  } else if (type != Type(TypeKind::BOOL) && this->type == WhileType::REPEAT) {
    throw error(
        "estrutura de repetição 'repeat' espera uma condição do tipo (bool) "
        "mas recebeu (" +
            type.to_string() + ")",
        this->line);
  };

  references->push_loop(cond_label, end_label);

  switch (this->type) {
    case WhileType::WHILE: {
      string ident_outer = references->get_scope_ident();
      os << cond_label << ":;" << std::endl;
      os << ident_outer << "if (";
      this->condition->compile_code(os);
      os << ") goto " << body_label << ";" << std::endl;
      os << ident_outer << "goto " << end_label << ";" << std::endl;

      references->push_scope();
      string ident = references->get_scope_ident();
      os << body_label << ":;" << std::endl;
      for (size_t i = 0; i < this->children.size(); i++) {
        os << ident;
        this->children[i]->compile_code(os);
        os << ";" << std::endl;
      }
      os << ident << "goto " << cond_label << ";" << std::endl;
      references->pop_scope();

      os << end_label << ":;";
      break;
    }
    case WhileType::REPEAT: {
      string ident_outer = references->get_scope_ident();
      os << start_label << ":;" << std::endl;

      references->push_scope();
      string ident = references->get_scope_ident();
      os << body_label << ":;" << std::endl;
      for (size_t i = 0; i < this->children.size(); i++) {
        os << ident;
        this->children[i]->compile_code(os);
        os << ";" << std::endl;
      }
      references->pop_scope();

      os << cond_label << ":;" << std::endl;
      os << ident_outer << "if (!(";
      this->condition->compile_code(os);
      os << ")) goto " << start_label << ";" << std::endl;
      os << ident_outer << "goto " << end_label << ";" << std::endl;

      os << end_label << ":;";
      break;
    }
  }

  references->pop_loop();
};

// Tipagem
Type WhileNode::get_type() const { return Type(TypeKind::VOID); };

// Cobertura dos retornos
ReturnCoverage WhileNode::get_return_coverage() const {
  ReturnCoverage block_coverage = ReturnCoverage::NONE;

  for (size_t i = 0; i < this->children.size(); i++) {
    ReturnCoverage coverage = this->children[i]->get_return_coverage();

    if (coverage == ReturnCoverage::GUARANTEED) {
      if (this->type == WhileType::REPEAT) {
        block_coverage = ReturnCoverage::GUARANTEED;
      } else {
        block_coverage = ReturnCoverage::PARTIAL;
      };

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
WhileNode::WhileNode(int line, ExpressionNode* condition, WhileType type)
    : Node(line), type(type), condition(condition) {};