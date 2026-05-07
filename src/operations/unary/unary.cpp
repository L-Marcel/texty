#include "implementations/unary.hpp"

// Inicialização de variáveis
bool UnaryOperations::initialized = false;
UnaryOperationsTypeTable UnaryOperations::table = {};

// Mapeamento de tipos
UnaryTypeCheckFunction UnaryOperations::get_type(const UnaryOperation key,
                                                 int line) {
  try {
    if (UnaryOperations::initialized == false) {
      UnaryOperations::initialize();
      UnaryOperations::initialized = true;
    };

    return UnaryOperations::table.at(key);
  } catch (const out_of_range& _) {
    throw error("operação não definida", line);
  }
};
void UnaryOperations::add_type(UnaryOperation key,
                               UnaryTypeCheckFunction function) {
  UnaryOperations::table.insert({key, function});
};

// Inicialização
void UnaryOperations::initialize() {
  // TODO: Restante das operações
};
