#pragma once
#include "includes.hpp"

template <typename T>
struct is_numeric : false_type {};

template <>
struct is_numeric<uint8_t> : true_type {};
template <>
struct is_numeric<int32_t> : true_type {};
template <>
struct is_numeric<int64_t> : true_type {};
template <>
struct is_numeric<float> : true_type {};
template <>
struct is_numeric<double> : true_type {};

bool check_if_is_numeric(const Type& type);