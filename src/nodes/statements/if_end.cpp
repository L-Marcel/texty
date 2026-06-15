#include "if_end.hpp"

#include "../../references/references.hpp"

// Debug
void IfEndNode::compile_dot(ostream& os) const {
  switch (this->type) {
    case IfEndType::EXPRESSION:
      Compiler::add_dot_node(os, this, "ELIF");
      Compiler::add_dot_relation(os, this, this->expression);
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children[i]);
      };
      Compiler::add_dot_relation(os, this, this->next);
      break;
    case IfEndType::UNWRAP:
      Compiler::add_dot_node(os, this, "ELIF: " + this->variable_id);
      Compiler::add_dot_relation(os, this, this->expression);
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children[i]);
      };
      Compiler::add_dot_relation(os, this, this->next);
      break;
    case IfEndType::ELSE:
      Compiler::add_dot_node(os, this, "ELSE");
      for (size_t i = 0; i < this->children.size(); i++) {
        Compiler::add_dot_relation(os, this, this->children[i]);
      };
      Compiler::add_dot_relation(os, this, this->next);
      break;
    default:
      Compiler::add_dot_node(os, this, "END_IF");
      break;
  }
};

// Código
void IfEndNode::compile_code(ostream& os) const {
  References* references = References::get_instance();

  switch (this->type) {
    case IfEndType::EXPRESSION: {
      Type type = this->expression->get_type();
      if (type != Type(TypeKind::BOOL))
        throw error(
            "a estrutura condicional 'if' espera uma condição do tipo (bool), "
            "mas recebeu (" +
                type.to_string() + ")",
            this->line);

      os << "if (";
      this->expression->compile_code(os);
      os << ") {" << std::endl;
      references->push_scope();

      string ident = references->get_scope_ident();
      for (size_t i = 0; i < this->children.size(); i++) {
        os << ident;
        this->children[i]->compile_code(os);
        os << ";" << std::endl;
      };

      references->pop_scope();
      ident = references->get_scope_ident();
      os << ident << "}";
      this->next->compile_code(os);
      break;
    }
    case IfEndType::UNWRAP: {
      Type type = this->expression->get_type();
      if (type.kind != TypeKind::OPTION)
        throw error(
            "a estrutura condicional 'if some' espera uma condição do tipo "
            "(option<unknown>), "
            "mas recebeu (" +
                type.to_string() + ")",
            this->line);

      os << "if (";
      this->expression->compile_code(os);
      os << ".is_some()";
      os << ") {" << std::endl;
      references->push_scope();

      string ident = references->get_scope_ident();
      os << ident;
      os << type.inner_type->to_production() << " ";
      os << this->variable_id << " = ";
      this->expression->compile_code(os);
      os << ".unwrap();" << std::endl;

      references->add_variable_reference(this->variable_id, *type.inner_type,
                                         true);
      for (size_t i = 0; i < this->children.size(); i++) {
        os << ident;
        this->children[i]->compile_code(os);
        os << ";" << std::endl;
      };

      references->pop_scope();
      ident = references->get_scope_ident();
      os << ident << "}";
      this->next->compile_code(os);
      break;
    }
    case IfEndType::ELSE: {
      os << " else {" << std::endl;
      references->push_scope();

      string ident = references->get_scope_ident();
      for (size_t i = 0; i < this->children.size(); i++) {
        os << ident;
        this->children[i]->compile_code(os);
        os << ";" << std::endl;
      };

      references->pop_scope();
      ident = references->get_scope_ident();
      os << ident << "}";
      break;
    }
    default:
      break;
  };
};

// Tipagem
Type IfEndNode::get_type() const { return Type(TypeKind::VOID); };

// Cobertura dos retornos
ReturnCoverage IfEndNode::get_return_coverage() const {
  if (this->type == IfEndType::END) {
    return ReturnCoverage::NONE;
  };

  ReturnCoverage block_coverage = ReturnCoverage::NONE;

  for (size_t i = 0; i < this->children.size(); i++) {
    ReturnCoverage coverage = this->children[i]->get_return_coverage();
    if (coverage == ReturnCoverage::GUARANTEED) {
      block_coverage = ReturnCoverage::GUARANTEED;
      
      if (i + 1 < this->children.size()) {
        throw error("código inalcançável detectado após instrução de retorno", 
                    this->children[i + 1]->line);
      };

      break;
    } else if (coverage == ReturnCoverage::PARTIAL) {
      block_coverage = ReturnCoverage::PARTIAL;
    }
  };

  if (this->type == IfEndType::ELSE) {
    return block_coverage; 
  };

  ReturnCoverage next_coverage = this->next ? this->next->get_return_coverage() : ReturnCoverage::NONE;

  if (block_coverage == ReturnCoverage::GUARANTEED && next_coverage == ReturnCoverage::GUARANTEED) {
    return ReturnCoverage::GUARANTEED;
  } else if (block_coverage != ReturnCoverage::NONE || next_coverage != ReturnCoverage::NONE) {
    return ReturnCoverage::PARTIAL;
  };

  return ReturnCoverage::NONE;
};

// Construtores
IfEndNode::IfEndNode(int line, ExpressionNode* expression, IfEndNode* next)
    : Node(line),
      type(IfEndType::EXPRESSION),
      variable_id(""),
      expression(expression),
      next(next) {};
IfEndNode::IfEndNode(int line, ExpressionNode* expression, string variable_id,
                     IfEndNode* next)
    : Node(line),
      type(IfEndType::UNWRAP),
      variable_id(variable_id),
      expression(expression),
      next(next) {};
IfEndNode::IfEndNode(int line, IfEndNode* next)
    : Node(line), 
      type(IfEndType::ELSE), 
      variable_id(""), 
      expression(nullptr),
      next(next) {};
IfEndNode::IfEndNode(int line) : Node(line), 
      type(IfEndType::END),       
      variable_id(""), 
      expression(nullptr),
      next(nullptr) {};