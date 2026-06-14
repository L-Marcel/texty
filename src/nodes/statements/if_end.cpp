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

// Construtores
IfEndNode::IfEndNode(int line, ExpressionNode* expression, IfEndNode* next)
    : Node(line),
      type(IfEndType::EXPRESSION),
      expression(expression),
      next(next) {};
IfEndNode::IfEndNode(int line, ExpressionNode* expression, string variable_id,
                     IfEndNode* next)
    : Node(line),
      type(IfEndType::UNWRAP),
      expression(expression),
      variable_id(variable_id),
      next(next) {};
IfEndNode::IfEndNode(int line, IfEndNode* next)
    : Node(line), type(IfEndType::ELSE), next(next) {};
IfEndNode::IfEndNode(int line) : Node(line), type(IfEndType::END) {};