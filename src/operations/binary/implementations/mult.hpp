#pragma once
#include "../../../helpers/numeric.hpp"
#include "../binary.hpp"

Type binary_mult_get_type(const Type& left, const Type& right, int line);
Type binary_div_get_type(const Type& left, const Type& right, int line);
Type binary_mod_get_type(const Type& left, const Type& right, int line);