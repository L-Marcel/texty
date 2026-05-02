#pragma once
#include "../binary.hpp"

template <typename T>
Value binary_plus(const Value& left, const Value& right, int line);
Type binary_plus_get_type(const Type& left, const Type& right, int line);

template <typename T>
Value binary_minus(const Value& left, const Value& right, int line);
Type binary_minus_get_type(const Type& left, const Type& right, int line);