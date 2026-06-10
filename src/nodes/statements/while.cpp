#include "while.hpp"

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
  // TODO
};

// Tipagem
Type WhileNode::get_type() const { return Type(TypeKind::VOID); };

// Construtores
WhileNode::WhileNode(int line, ExpressionNode* condition, WhileType type)
    : Node(line), type(type), condition(condition) {};