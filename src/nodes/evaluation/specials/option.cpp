#include "option.hpp"

// Avaliação
Value OptionNode::evaluate() { return Value(this->value); };

// Construtores
OptionNode::OptionNode(int line, Option value)
    : ExpressionNode(line), value(value) {};