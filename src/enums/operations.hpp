#pragma once

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
  CONCAT,
  PLUS,
  MINUS,
  MULT,
  DIV,
  MOD,
  EXP
};

enum class UnaryOperation { MINUS, REV, NOT, REF, DEREF, INCREMENT, DECREMENT };
