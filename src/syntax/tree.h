#include <cstdint>
#include <string>

using namespace std;

enum NodeType {
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
  NodeType type;

  virtual ~Node() = default;

 protected:
  Node(int line, NodeType type) : line(line), type(type) {};
};

struct Id : public Node {
  string name;
};

struct Byte : public Node {
  Byte(int line) : Node(line, NodeType::BYTE) {};
  uint8_t value;
};

struct Int : public Node {
  Int(int line) : Node(line, NodeType::INT) {};
  int32_t value;
};

struct Long : public Node {
  Long(int line) : Node(line, NodeType::LONG) {};
  int64_t value;
};

struct Float : public Node {
  Float(int line) : Node(line, NodeType::FLOAT) {};
  float value;
};

struct Double : public Node {
  Double(int line) : Node(line, NodeType::DOUBLE) {};
  double value;
};

struct Bool : public Node {
  Bool(int line) : Node(line, NodeType::BOOL) {};
  bool value;
};

struct String : public Node {
  String(int line) : Node(line, NodeType::STRING) {};
  string value;
};

struct Char : public Node {
  Char(int line) : Node(line, NodeType::CHAR) {};
  char value;
};

struct Pointer : public Node {
  Pointer(int line) : Node(line, NodeType::POINTER) {};
  Node* value;
};

struct Option : public Node {
  Option(int line) : Node(line, NodeType::OPTION) {};
  bool has_value;
  Node* value;
};