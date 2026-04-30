#pragma once
#include <cstdint>
#include <ostream>
#include <string>

using namespace std;

enum class NodeType {
  UNKNOWN,
  VOID,
  BYTE,
  INT,
  LONG,
  FLOAT,
  DOUBLE,
  BOOL,
  STRING,
  CHAR,
  POINTER,
  OPTION
};

struct Node {
  int line;

  virtual void print(ostream& os) const;
  virtual NodeType get_type() const;
  virtual ~Node();

 protected:
  Node(int line);
};

enum class BinaryOperation {
  OR,
  AND,
  BITWISE_OR,
  XOR,
  BITWISE_AND,
  EQ,
  NOT_EQ,
  LT,
  GT,
  LT_EQ,
  GT_EQ,
  IN,
  INCREMENT,
  PLUS,
  MINUS,
  MULT,
  DIV,
  MOD,
  EXP
};

struct BinaryOperationNode : public Node {
  BinaryOperation operation;
  Node* left;
  Node* right;

  BinaryOperationNode(BinaryOperation operation, Node* left, Node* right);
  void print(ostream& os) const override;
  NodeType get_type() const override;
};

enum class UnaryOperation { MINUS, REV, NOT, REF, INCREMENT, DECREMENT };

struct UnaryOperationNode : public Node {
  UnaryOperation operation;
  bool postfix = false;
  Node* node;

  UnaryOperationNode(UnaryOperation operation, Node* node);
  UnaryOperationNode(bool postfix, UnaryOperation operation, Node* node);
  void print(ostream& os) const override;
  NodeType get_type() const override;
};