#pragma once
#include "../references/reference.hpp"

struct Node {
  int line;

  virtual void print(ostream& os) const;
  virtual Type get_type() const;
  virtual ~Node() = default;

 protected:
  Node(int line);
};

// TODO: Adicionar nó executável