#pragma once
#include "../references/reference.hpp"

struct Node {
  int line;

  virtual void compile_dot(ostream& os) const;
  virtual void compile_code(ostream& os) const;
  virtual Type get_type() const;
  virtual ~Node() = default;

 protected:
  Node(int line);
};

// TODO: Adicionar nó executável