#include "break.hpp"

#include "../../references/references.hpp"
// Debug
void BreakNode::compile_dot(ostream& os) const {
  Compiler::add_dot_node(os, this, "BREAK");
};

// Código
void BreakNode::compile_code(ostream& os) const {
  References* references = References::get_instance();
  string break_label = references->get_break_label();

  if (break_label == "") {
    // TODO - Ainda pode em um switch
    throw error("comando 'break' usado fora de um laço de repetição",
                this->line);
  };

  os << "goto " << break_label << ";";
};

// Tipagem
Type BreakNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
BreakNode::BreakNode(int line) : Node(line) {};