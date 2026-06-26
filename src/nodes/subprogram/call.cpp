#include "call.hpp"

#include "../../helpers/function.hpp"
#include "../../references/references.hpp"

// Debug
void SubprogramCallNode::compile_dot(ostream& os) const {
  if (this->call_type == CallType::ACCESS) {
    Compiler::add_dot_node(os, this, "CALL");
    Compiler::add_dot_relation(os, this, this->access);
  } else {
    Compiler::add_dot_node(os, this,
                           "CONVERT: " + this->target_type.to_string());
  };

  for (size_t i = 0; i < this->params.size(); i++) {
    Compiler::add_dot_relation(os, this, this->params[i]);
  };
};

// Código
void SubprogramCallNode::compile_code(ostream& os) const {
  this->get_type();

  if (this->call_type == CallType::CONVERTION) {
    Type source_type = this->params[0]->get_type();
    if (this->target_type.kind == TypeKind::STRING) {
      if (source_type.kind == TypeKind::POINTER) {
        os << "pointer_to_string(";
      } else {
        os << source_type.get_name() << "_to_string(";
      };
    } else {
      os << "txy_" << source_type.get_name() << "_to_"
         << this->target_type.get_name() << "(";
    };
    this->params[0]->compile_code(os);
    os << ")";
  } else {
    if (this->access->access_type == AccessType::BASE) {
      AccessBaseNode* base = this->access->base;
      if (base->access_type == AccessBaseType::ID &&
          base->name == "txy_format") {
        string signature = "";
        for (size_t i = 1; i < this->params.size(); i++) {
          signature += this->params[i]->get_type().get_name();
          if (i != this->params.size() - 1) signature += "_";
        };

        string name = "__txy_fmt_" + signature;
        static set<string> generated_formats;
        if (generated_formats.find(signature) == generated_formats.end()) {
          generated_formats.insert(signature);

          generated_implementations << "char* " << name
                                    << "(const char* pattern";
          for (size_t i = 1; i < this->params.size(); i++) {
            generated_implementations
                << ", " << this->params[i]->get_type().to_production() << " arg"
                << i;
          };
          generated_implementations << ") {" << std::endl;

          size_t count = this->params.size() - 1;
          generated_implementations
              << "  array_string array = array_string_create(" << count
              << ", \"\");" << std::endl;

          for (size_t i = 1; i < this->params.size(); i++) {
            Type type = this->params[i]->get_type();
            string to_string_function = type.get_name() + "_to_string";

            if (type.kind == TypeKind::POINTER) {
              to_string_function = "pointer_to_string";
            };

            generated_implementations << "  array.pointer[" << (i - 1)
                                      << "] = " << to_string_function << "(arg"
                                      << i << ");" << std::endl;
          };

          generated_implementations << "  return txy_format(pattern, array);"
                                    << std::endl;
          generated_implementations << "};" << std::endl << std::endl;
        };

        os << name << "(";
        for (size_t i = 0; i < this->params.size(); i++) {
          this->params[i]->compile_code(os);
          if (i != this->params.size() - 1) os << ", ";
        }
        os << ")";

        return;
      } else if (base->access_type == AccessBaseType::ID &&
                 base->name == "txy_delete" && this->params.size() == 1) {
        Type type = this->params[0]->get_type();

        if (type.inner_type->kind == TypeKind::ARRAY || type.inner_type->kind == TypeKind::OPTION || type.inner_type->kind == TypeKind::NAMED) {
          os << type.inner_type->get_name() << "_free(";
          if (type.inner_type->kind == TypeKind::NAMED) {
            os << "&(";
            this->params[0]->compile_code(os);
            os << ")";
          } else {
            this->params[0]->compile_code(os);
          }
          os << ")";
        } else if (type.inner_type->kind == TypeKind::POINTER) {
          os << "(*(";
          this->params[0]->compile_code(os);
          os << ") = NULL)";
        } else {
          os << "(*(";
          this->params[0]->compile_code(os);
          os << ") = " << type.inner_type->get_default_value() << ")";
        }
        return;
      } else if (base->access_type == AccessBaseType::ID &&
                 base->name == "txy_join" && this->params.size() > 1) {
        os << "txy_join(";
        this->params[0]->compile_code(os);
        os << ", array_string_from_values(";
        os << "(char*[]){";

        for (size_t i = 1; i < this->params.size(); i++) {
          this->params[i]->compile_code(os);
          if (i != this->params.size() - 1) {
            os << ", ";
          };
        };

        os << "}, ";
        os << (this->params.size() - 1) << ", ";
        os << (this->params.size() - 1) << ", ";
        os << "\"\"";
        os << "))";
        return;
      };
    };

    this->access->compile_code(os);
    os << "(";
    for (size_t i = 0; i < this->params.size(); i++) {
      this->params[i]->compile_code(os);
      if (i != this->params.size() - 1) {
        os << ", ";
      };
    };
    os << ")";
  };
};

// Tipagem
Type SubprogramCallNode::get_type() const {
  if (this->call_type == CallType::ACCESS) {
    Reference* reference = this->access->get_reference(this->line);
    string reference_name = this->access->to_string();
    vector<Type> types;
    if (reference->reference_type == ReferenceType::FUNCTION) {
      FunctionReference* function_reference = (FunctionReference*)reference;

      string reference_types =
          types_to_string(function_reference->params, false);
      string params_types = expressions_types_to_string(this->params, false);

      bool is_varchar_function = check_if_is_varchar_function(reference_name);
      if (is_varchar_function)
        reference_types = get_varchar_function_types_as_string(reference_name);

      vector<Type> required_varchar_types =
          get_required_varchar_function_types(reference_name);
      Type others_varchar_types =
          get_others_varchar_function_types(reference_name);

      if (function_reference->params.size() != this->params.size() &&
          !is_varchar_function) {
        throw error("número de parâmetros incorreto na chamada, a função \'" +
                        reference_name + "\' espera receber (" +
                        reference_types + ") mas recebeu (" + params_types +
                        ")",
                    this->line);
      } else if (is_varchar_function &&
                 this->params.size() < required_varchar_types.size()) {
        throw error("número de parâmetros incorreto na chamada, a função \'" +
                        reference_name + "\' espera receber (" +
                        reference_types + ") mas recebeu (" + params_types +
                        ")",
                    this->line);
      };

      if (!is_varchar_function) {
        for (size_t i = 0; i < function_reference->params.size(); i++) {
          if (this->params[i]->get_type() != function_reference->params[i]) {
            throw error(
                "tipo incorreto nos parâmetros da chamada, a função \'" +
                    reference_name + "\' espera receber (" + reference_types +
                    ") mas recebeu (" + params_types + ")",
                this->line);
          };
        };
      } else {
        for (size_t i = 0; i < required_varchar_types.size(); i++) {
          if (this->params[i]->get_type() != required_varchar_types[i]) {
            throw error(
                "tipo incorreto nos parâmetros da chamada, a função \'" +
                    reference_name + "\' espera receber (" + reference_types +
                    ") mas recebeu (" + params_types + ")",
                this->line);
          };
        };

        for (size_t i = required_varchar_types.size(); i < this->params.size();
             i++) {
          if (this->params[i]->get_type() != others_varchar_types &&
              others_varchar_types != Type(TypeKind::UNKNOWN)) {
            throw error(
                "tipo incorreto nos parâmetros da chamada, a função \'" +
                    reference_name + "\' espera receber (" + reference_types +
                    ") mas recebeu (" + params_types + ") ",
                this->line);
          };
        };
      };

      return function_reference->node_type;
    } else if (reference->reference_type == ReferenceType::PROCEDURE) {
      ProcedureReference* procedure_reference = (ProcedureReference*)reference;

      string reference_types =
          types_to_string(procedure_reference->params, false);
      string params_types = expressions_types_to_string(this->params, false);

      if (procedure_reference->params.size() != this->params.size()) {
        throw error(
            "número de parâmetros incorreto na chamada, o procedimento \'" +
                reference_name + "\' espera receber (" + reference_types +
                ") mas recebeu (" + params_types + ")",
            this->line);
      };

      for (size_t i = 0; i < procedure_reference->params.size(); i++) {
        if (
          this->params[i]->get_type() != procedure_reference->params[i]
          && (reference_name != "delete" || (
            reference_name == "delete"
            && this->params[i]->get_type().kind != TypeKind::POINTER
          ))
        ) {
          throw error(
              "tipo incorreto nos parâmetros da chamada, o procedimento \'" +
                  reference_name + "\' espera receber (" + reference_types +
                  ") mas recebeu (" + params_types + ")",
              this->line);
        };
      };

      return Type(TypeKind::VOID);
    } else {
      throw error("identificador \'" + reference_name +
                      "\' não pertence a um subprograma",
                  this->line);
    };
  } else {
    return this->target_type;
  };
};

// Construtores
SubprogramCallNode::SubprogramCallNode(int line, AccessNode* access,
                                       vector<ExpressionNode*> params)
    : Node(line),
      call_type(CallType::ACCESS),
      access(access),
      params(params),
      target_type(Type(TypeKind::UNKNOWN)) {};
SubprogramCallNode::SubprogramCallNode(int line, Type target_type,
                                       vector<ExpressionNode*> params)
    : Node(line),
      call_type(CallType::CONVERTION),
      params(params),
      target_type(target_type) {};