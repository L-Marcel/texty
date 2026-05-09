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
  UnaryOperations::add_type(UnaryOperation::MINUS, unary_minus_get_type);
  UnaryOperations::add_type(UnaryOperation::NOT, unary_not_get_type);
  UnaryOperations::add_type(UnaryOperation::REV, unary_rev_get_type);
  UnaryOperations::add_type(UnaryOperation::REF, unary_ref_get_type);
};
