#include "return.hpp"

#include "../../references/references.hpp"

// Debug
void ReturnNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "RETURN");
  if (this->type == ReturnNodeType::EXPRESSION)
    Compiler::add_dot_relation(os, this, this->expression);
};

// Código
void ReturnNode::compile_code(ostream& os) const {
  References* references = References::get_instance();
  os << "return";
  if (this->type == ReturnNodeType::EXPRESSION) {
    os << " ";
    this->expression->compile_code(os);
  } else if (references->get_main_is_procedure()) {
    os << " 0";
  };
};

// Tipagem
Type ReturnNode::get_type() const {
  References* references = References::get_instance();
  Type return_type = references->get_suprogram_return_type();

  if (this->type == ReturnNodeType::EMPTY &&
      return_type.kind == TypeKind::VOID) {
    return Type(TypeKind::VOID);
  } else if (this->type == ReturnNodeType::EXPRESSION &&
             return_type == this->expression->get_type()) {
    return return_type;
  } else if (this->type == ReturnNodeType::EXPRESSION) {
    throw error("subprograma espera retorno do tipo (" +
                    return_type.to_string() + ") mas recebeu (" +
                    this->expression->get_type().to_string() + ")",
                this->line);
  } else {
    throw error("não foi possível determinar o retorno do subprograma",
                this->line);
  };
};

// Cobertura do retorno
ReturnCoverage ReturnNode::get_return_coverage() const {
  return ReturnCoverage::GUARANTEED;
};

// Construtores
ReturnNode::ReturnNode(int line)
    : Node(line),
      type(ReturnNodeType::EMPTY),
      expression(nullptr),
      expected_type(Type(TypeKind::VOID)) {};
ReturnNode::ReturnNode(int line, ExpressionNode* expression)
    : Node(line),
      type(ReturnNodeType::EXPRESSION),
      expression(expression),
      expected_type(Type(TypeKind::UNKNOWN)) {};
