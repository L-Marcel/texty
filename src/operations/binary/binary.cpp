#include "implementations/sum.hpp"

// Inicialização de variáveis
bool BinaryOperations::initialized = false;
BinaryOperationsTypeTable BinaryOperations::table = {};

// Mapeamento de tipos
BinaryTypeCheckFunction BinaryOperations::get_type(const BinaryOperation key,
                                                   int line) {
  try {
    if (BinaryOperations::initialized == false) {
      BinaryOperations::initialize();
      BinaryOperations::initialized = true;
    };

    return BinaryOperations::table.at(key);
  } catch (const out_of_range& _) {
    throw error("operação não definida", line);
  }
};
void BinaryOperations::add_type(BinaryOperation key,
                                BinaryTypeCheckFunction function) {
  BinaryOperations::table.insert({key, function});
};

// Inicialização
void BinaryOperations::initialize() {
  BinaryOperations::add_type(BinaryOperation::PLUS, binary_plus_get_type);
  BinaryOperations::add_type(BinaryOperation::MINUS, binary_minus_get_type);

  // TODO: Restante das operações
  // TODO: Operações unárias (outro arquivo)
};
