#include "implementations/sum.hpp"

// Inicialização de variáveis
bool BinaryOperations::initialized = false;
BinaryOperationsFunctionTable BinaryOperations::function_table = {};
BinaryOperationsTypeTable BinaryOperations::type_table = {};

// Mapeamento de funções
BinaryEvaluationFunction BinaryOperations::get_function(
    const BinaryOperation key, int line) {
  try {
    if (BinaryOperations::initialized == false) {
      BinaryOperations::initialize();
      BinaryOperations::initialized = true;
    };

    return BinaryOperations::function_table.at(key);
  } catch (const out_of_range& _) {
    throw error("operação não definida", line);
  }
};
void BinaryOperations::add_function(BinaryOperation key,
                                    BinaryEvaluationFunction function) {
  BinaryOperations::function_table.insert({key, function});
};

// Mapeamento de tipos
BinaryTypeCheckFunction BinaryOperations::get_type(const BinaryOperation key,
                                                   int line) {
  try {
    if (BinaryOperations::initialized == false) {
      BinaryOperations::initialize();
      BinaryOperations::initialized = true;
    };

    return BinaryOperations::type_table.at(key);
  } catch (const out_of_range& _) {
    throw error("operação não definida", line);
  }
};
void BinaryOperations::add_type(BinaryOperation key,
                                BinaryTypeCheckFunction function) {
  BinaryOperations::type_table.insert({key, function});
};

// Inicialização
void BinaryOperations::initialize() {
  BinaryOperations::add_type(BinaryOperation::PLUS, binary_plus_get_type);
  BinaryOperations::add_function(BinaryOperation::PLUS, binary_plus<uint8_t>);
  BinaryOperations::add_function(BinaryOperation::PLUS, binary_plus<int32_t>);
  BinaryOperations::add_function(BinaryOperation::PLUS, binary_plus<int64_t>);
  BinaryOperations::add_function(BinaryOperation::PLUS, binary_plus<float>);
  BinaryOperations::add_function(BinaryOperation::PLUS, binary_plus<double>);

  BinaryOperations::add_type(BinaryOperation::MINUS, binary_minus_get_type);
  BinaryOperations::add_function(BinaryOperation::MINUS, binary_minus<uint8_t>);
  BinaryOperations::add_function(BinaryOperation::MINUS, binary_minus<int32_t>);
  BinaryOperations::add_function(BinaryOperation::MINUS, binary_minus<int64_t>);
  BinaryOperations::add_function(BinaryOperation::MINUS, binary_minus<float>);
  BinaryOperations::add_function(BinaryOperation::MINUS, binary_minus<double>);

  // TODO: Restante das operações
  // TODO: Operações unárias (outro arquivo)
};
