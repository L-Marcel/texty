#include "literals.h"

// Tipagem
NodeType ByteNode::get_type() const { return NodeType::BYTE; };
NodeType IntNode::get_type() const { return NodeType::INT; };
NodeType LongNode::get_type() const { return NodeType::LONG; };
NodeType FloatNode::get_type() const { return NodeType::FLOAT; };
NodeType DoubleNode::get_type() const { return NodeType::DOUBLE; };
NodeType BoolNode::get_type() const { return NodeType::BOOL; };
NodeType StringNode::get_type() const { return NodeType::STRING; };
NodeType CharNode::get_type() const { return NodeType::CHAR; };

// Construtores
ByteNode::ByteNode(int line, uint8_t value) : Node(line), value(value) {};
IntNode::IntNode(int line, int32_t value) : Node(line), value(value) {};
LongNode::LongNode(int line, int64_t value) : Node(line), value(value) {};
FloatNode::FloatNode(int line, float value) : Node(line), value(value) {};
DoubleNode::DoubleNode(int line, double value) : Node(line), value(value) {};
BoolNode::BoolNode(int line, bool value) : Node(line), value(value) {};
StringNode::StringNode(int line, string value) : Node(line), value(value) {};
CharNode::CharNode(int line, char value) : Node(line), value(value) {};