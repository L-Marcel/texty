#include "continue.hpp"

#include "../../references/references.hpp"

// Debug
void ContinueNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "CONTINUE");
};

// Código
void ContinueNode::compile_code(ostream& os) const {
  References* references = References::get_instance();
  string continue_label = references->get_continue_label();

  if (continue_label == "") {
    throw error("comando 'continue' usado fora de um laço de repetição",
                this->line);
  };

  os << "goto " << continue_label << ";";
};

// Tipagem
Type ContinueNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
ContinueNode::ContinueNode(int line) : Node(line) {};