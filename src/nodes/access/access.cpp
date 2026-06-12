#include "access.hpp"

#include "../../references/references.hpp"
#include "../subprogram/call.hpp"

// Debug
void AccessNode::compile_dot(ostream& os) const {
  switch (this->access_type) {
    case AccessType::DOT:
      Compiler::add_dot_node(os, this, "DOT: " + this->name.substr(4));
      Compiler::add_dot_relation(os, this, this->previous);
      break;
    case AccessType::BRACKET:
      Compiler::add_dot_node(os, this, "BRACKET");
      Compiler::add_dot_relation(os, this, this->previous);
      Compiler::add_dot_relation(os, this, this->expression);
      break;
    case AccessType::CALL:
      Compiler::add_dot_node(os, this, "ACCESS");
      Compiler::add_dot_relation(os, this, this->call);
      break;
    case AccessType::STATIC:
      Compiler::add_dot_node(os, this, "STATIC: " + this->name.substr(4));
      Compiler::add_dot_relation(os, this, this->previous);
      break;
    case AccessType::BASE:
      Compiler::add_dot_node(os, this, "ACCESS");
      Compiler::add_dot_relation(os, this, this->base);
      break;
    default:
      break;
  }
};

// Código
void AccessNode::compile_code(ostream& os) const {
  switch (this->access_type) {
    case AccessType::DOT:
      this->previous->compile_code(os);
      os << "." << this->name;
      break;
    case AccessType::BRACKET:
      this->previous->compile_code(os);
      os << "[";
      this->expression->compile_code(os);
      os << "]";
      break;
    case AccessType::CALL:
      this->call->compile_code(os);
      break;
    case AccessType::STATIC:
      this->previous->compile_code(os);
      os << "::" << this->name;
      break;
    default:
      this->base->compile_code(os);
      break;
  };
  this->get_type();
};

// Tipagem
Type AccessNode::get_type() const {
  switch (this->access_type) {
    case AccessType::DOT:
      // TODO - Tem que considerar o caminho
      return References::get_instance()
          ->get_reference(line, this->name)
          ->node_type;
    case AccessType::BRACKET: {
      Type type = this->previous->get_type();
      if (type.kind != TypeKind::ARRAY)
        throw new error("acesso com colchetes é reservado para arrays",
                        this->line);
      return *type.inner_type;
    }
    case AccessType::CALL:
      return this->call->get_type();
    case AccessType::STATIC:
      // TODO - Tem que considerar o caminho
      return References::get_instance()
          ->get_reference(line, this->name)
          ->node_type;
    default:
      // TODO - Tem que considerar o caminho
      return this->base->get_type();
  };
};

// Referências
Reference* AccessNode::get_reference(int line) const {
  switch (this->access_type) {
    case AccessType::DOT:
      // TODO - Tem que ser uma referência que considere a base
      return References::get_instance()->get_reference(line, this->name);
    case AccessType::BRACKET:
      return this->previous->get_reference(line);
    case AccessType::CALL:
      if (this->call->call_type == CallType::ACCESS) {
        return this->call->access->get_reference(line);
      } else {
        throw error("tentativa de acesso a tipo primitivo", line);
      };
    case AccessType::STATIC:
      // TODO - Tem que ser uma referência que considere a base
      return References::get_instance()->get_reference(line, this->name);
    default:
      return this->base->get_reference(line);
  };
};

// Construtores
AccessNode::AccessNode(int line, AccessBaseNode* base)
    : ExpressionNode(line), access_type(AccessType::BASE), base(base) {};
AccessNode::AccessNode(int line, SubprogramCallNode* call)
    : ExpressionNode(line), access_type(AccessType::CALL), call(call) {};
AccessNode::AccessNode(int line, string name, AccessNode* previous,
                       AccessType access_type)
    : ExpressionNode(line, name),
      access_type(access_type),
      previous(previous) {};
AccessNode::AccessNode(int line, AccessNode* previous,
                       ExpressionNode* expression)
    : ExpressionNode(line),
      access_type(AccessType::BRACKET),
      previous(previous),
      expression(expression) {};