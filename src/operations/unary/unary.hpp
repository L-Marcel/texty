#pragma once
#include "../../nodes/evaluation/unary.hpp"

using UnaryTypeCheckFunction =
    function<Type(const Type&, int line)>;
using UnaryOperationsTypeTable = map<UnaryOperation, UnaryTypeCheckFunction>;

struct UnaryOperations {
  static bool initialized;
  static UnaryOperationsTypeTable table;
  static UnaryTypeCheckFunction get_type(UnaryOperation key, int line);
  static void add_type(UnaryOperation key, UnaryTypeCheckFunction function);
  static void initialize();
};