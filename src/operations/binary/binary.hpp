#pragma once
#include "../../helpers/numeric.hpp"
#include "../../nodes/evaluation/binary.hpp"

using BinaryTypeCheckFunction =
    function<Type(const Type&, const Type&, int line)>;
using BinaryOperationsTypeTable = map<BinaryOperation, BinaryTypeCheckFunction>;

struct BinaryOperations {
  static bool initialized;
  static BinaryOperationsTypeTable table;
  static BinaryTypeCheckFunction get_type(BinaryOperation key, int line);
  static void add_type(BinaryOperation key, BinaryTypeCheckFunction function);
  static void initialize();
};