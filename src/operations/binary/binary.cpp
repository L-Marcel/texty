#include "implementations/and.hpp"
#include "implementations/bit_and.hpp"
#include "implementations/bit_or.hpp"
#include "implementations/bit_xor.hpp"
#include "implementations/equals.hpp"
#include "implementations/exp.hpp"
#include "implementations/mult.hpp"
#include "implementations/or.hpp"
#include "implementations/rel.hpp"
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

    return BinaryOperations::table[key];
  } catch (const out_of_range& _) {
    throw error("tipos suportados da operação não definidos", line);
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

  BinaryOperations::add_type(BinaryOperation::AND, binary_and_get_type);
  BinaryOperations::add_type(BinaryOperation::OR, binary_or_get_type);
  BinaryOperations::add_type(BinaryOperation::EXP, binary_exp_get_type);
  BinaryOperations::add_type(BinaryOperation::EQ, binary_eq_get_type);
  BinaryOperations::add_type(BinaryOperation::NOT_EQ, binary_not_eq_get_type);
  BinaryOperations::add_type(BinaryOperation::GT, binary_gt_get_type);
  BinaryOperations::add_type(BinaryOperation::GT_EQ, binary_gt_eq_get_type);
  BinaryOperations::add_type(BinaryOperation::LT, binary_lt_get_type);
  BinaryOperations::add_type(BinaryOperation::LT_EQ, binary_lt_eq_get_type);
  BinaryOperations::add_type(BinaryOperation::IN, binary_in_get_type);
  BinaryOperations::add_type(BinaryOperation::MULT, binary_mult_get_type);
  BinaryOperations::add_type(BinaryOperation::DIV, binary_div_get_type);
  BinaryOperations::add_type(BinaryOperation::MOD, binary_mod_get_type);
  BinaryOperations::add_type(BinaryOperation::BITWISE_OR,
                             binary_bit_or_get_type);
  BinaryOperations::add_type(BinaryOperation::BITWISE_AND,
                             binary_bit_and_get_type);
  BinaryOperations::add_type(BinaryOperation::XOR, binary_xor_get_type);

  // TODO: Restante das operações
};
