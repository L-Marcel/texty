#include "sum.hpp"

template <typename T>
Value binary_plus(const Value& left, const Value& right, int line) {
  if constexpr (is_numeric<T>::value) {
    return Value(get<T>(left) + get<T>(right));
  } else {
    throw error("operação não definida para os respectivos tipos", line);
  }
};

Type binary_plus_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_numeric(left) && check_if_is_numeric(right) &&
      left == right) {
    return left;
  } else {
    throw error("operação não definida para os respectivos tipos", line);
  }
};

template <typename T>
Value binary_minus(const Value& left, const Value& right, int line) {
  if constexpr (is_numeric<T>::value) {
    return Value(get<T>(left) - get<T>(right));
  } else {
    throw error("operação não definida para os respectivos tipos", line);
  }
};

Type binary_minus_get_type(const Type& left, const Type& right, int line) {
  if (check_if_is_numeric(left) && check_if_is_numeric(right) &&
      left == right) {
    return left;
  } else {
    throw error("operação não definida para os respectivos tipos", line);
  }
};

template Value binary_plus<uint8_t>(const Value&, const Value&, int line);
template Value binary_plus<int32_t>(const Value&, const Value&, int line);
template Value binary_plus<int64_t>(const Value&, const Value&, int line);
template Value binary_plus<float>(const Value&, const Value&, int line);
template Value binary_plus<double>(const Value&, const Value&, int line);
template Value binary_minus<uint8_t>(const Value&, const Value&, int line);
template Value binary_minus<int32_t>(const Value&, const Value&, int line);
template Value binary_minus<int64_t>(const Value&, const Value&, int line);
template Value binary_minus<float>(const Value&, const Value&, int line);
template Value binary_minus<double>(const Value&, const Value&, int line);