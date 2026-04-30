#pragma once
#include "tree.h"

struct ByteNode : public Node {
  uint8_t value;

  ByteNode(int line, uint8_t value);
  void print(ostream& os) const override;
  NodeType get_type() const override;
};

struct IntNode : public Node {
  int32_t value;

  IntNode(int line, int32_t value);
  void print(ostream& os) const override;
  NodeType get_type() const override;
};

struct LongNode : public Node {
  int64_t value;

  LongNode(int line, int64_t value);
  void print(ostream& os) const override;
  NodeType get_type() const override;
};

struct FloatNode : public Node {
  float value;

  FloatNode(int line, float value);
  void print(ostream& os) const override;
  NodeType get_type() const override;
};

struct DoubleNode : public Node {
  double value;

  DoubleNode(int line, double value);
  void print(ostream& os) const override;
  NodeType get_type() const override;
};

struct BoolNode : public Node {
  bool value;

  BoolNode(int line, bool value);
  void print(ostream& os) const override;
  NodeType get_type() const override;
};

struct StringNode : public Node {
  string value;

  StringNode(int line, string value);
  void print(ostream& os) const override;
  NodeType get_type() const override;
};

struct CharNode : public Node {
  char value;

  CharNode(int line, char value);
  void print(ostream& os) const override;
  NodeType get_type() const override;
};