#include "access.hpp"

#include "../../references/references.hpp"
#include "../subprogram/call.hpp"

static bool is_enum_type_access(const AccessNode* access, string& enum_name) {
  if (access->access_type != AccessType::BASE || access->base == nullptr ||
      access->base->access_type != AccessBaseType::ID) {
    return false;
  }

  enum_name = access->base->name;
  return References::get_instance()->has_enum_reference(enum_name);
};

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
    case AccessType::DOT: {
      string enum_name;
      if (is_enum_type_access(this->previous, enum_name)) {
        this->get_type();
        os << enum_name << "_" << this->name.substr(4);
        break;
      }
      this->previous->compile_code(os);
      Type previous_type = this->previous->get_type();
      if (previous_type.kind == TypeKind::NAMED) {
          os << "->" << this->name;
      } else {
          os << "." << this->name;
      }
      break;
    }
    case AccessType::BRACKET: {
      string enum_name;
      if (is_enum_type_access(this->previous, enum_name)) {
        this->get_type();
        os << enum_name << "_from_int(";
        this->expression->compile_code(os);
        os << ")";
        break;
      }
      this->previous->compile_code(os);
      os << ".pointer[";
      this->expression->compile_code(os);
      os << "]";
      break;
    }
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

// String
string AccessNode::to_string() const {
  switch (this->access_type) {
    case AccessType::DOT:
      return this->previous->to_string() + "." + this->name.substr(4);
    case AccessType::BRACKET:
      return this->previous->to_string() + "[...]";
    case AccessType::CALL:
      return this->call->access->to_string() + "(...)";
    case AccessType::STATIC:
      return this->previous->to_string() + "::" + this->name.substr(4);
    default:
      return this->base->to_string();
  };
};

// Tipagem
Type AccessNode::get_type() const {
  switch (this->access_type) {
    case AccessType::DOT: {
      string enum_name;
      if (is_enum_type_access(this->previous, enum_name)) {
        if (!References::get_instance()->has_enum_value(enum_name, this->name)) {
          throw error("tentativa inválida de acesso ao valor '" +
                          this->name.substr(4) +
                          "' não declarado na enumeração '" +
                          enum_name.substr(4) + "'",
                      this->line);
        }
        return Type(TypeKind::NAMED, enum_name);
      }

      Type previous_type = this->previous->get_type();
      if (previous_type.kind != TypeKind::NAMED) {
        throw error("tentativa inválida de acesso ao campo '" +
                        this->name.substr(4) + "' em valor do tipo (" +
                        previous_type.to_string() + ")",
                    this->line);
      }

      vector<pair<string, Type>> attributes =
          References::get_instance()->get_struct_reference(previous_type.name);
      for (size_t i = 0; i < attributes.size(); i++) {
        if (attributes[i].first == this->name) return attributes[i].second;
      }

      throw error("tentativa inválida de acesso ao campo '" +
                      this->name.substr(4) + "' não declarado na estrutura '" +
                      previous_type.name.substr(4) + "'",
                  this->line);
    }
    case AccessType::BRACKET: {
      string enum_name;
      if (is_enum_type_access(this->previous, enum_name)) {
        Type index_type = this->expression->get_type();
        if (index_type.kind != TypeKind::INT) {
          throw error("índice de enumeração deve ser do tipo int", this->line);
        }
        return Type(TypeKind::NAMED, enum_name);
      }

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
    case AccessType::DOT: {
      Reference* prev = this->previous->get_reference(line);
      if (!prev) throw error("referência base não encontrada", line);
      Reference* prop = prev->get_property(this->name);
      if (!prop) {
        throw error("tentativa inválida de acesso ao campo '" + this->name.substr(4) + "' não declarado na estrutura", line);
      }
      return prop;
    }
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
