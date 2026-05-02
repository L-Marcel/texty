#pragma once
#include "../../helpers/numeric.hpp"
#include "../../nodes/evaluation/binary.hpp"

using BinaryEvaluationFunction =
    function<Value(const Value&, const Value&, int line)>;
using BinaryTypeCheckFunction =
    function<Type(const Type&, const Type&, int line)>;
using BinaryOperationsFunctionTable =
    map<BinaryOperation, BinaryEvaluationFunction>;
using BinaryOperationsTypeTable = map<BinaryOperation, BinaryTypeCheckFunction>;

struct BinaryOperations {
  static bool initialized;
  static BinaryOperationsFunctionTable function_table;
  static BinaryOperationsTypeTable type_table;
  static BinaryEvaluationFunction get_function(BinaryOperation key, int line);
  static BinaryTypeCheckFunction get_type(BinaryOperation key, int line);
  static void add_function(BinaryOperation key,
                           BinaryEvaluationFunction function);
  static void add_type(BinaryOperation key, BinaryTypeCheckFunction function);
  static void initialize();
};