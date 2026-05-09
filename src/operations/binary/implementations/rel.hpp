#pragma once
#include "../../../helpers/numeric.hpp"
#include "../binary.hpp"

Type binary_eq_get_type(const Type& left, const Type& right, int line);
Type binary_not_eq_get_type(const Type& left, const Type& right, int line);
Type binary_gt_get_type(const Type& left, const Type& right, int line);
Type binary_lt_get_type(const Type& left, const Type& right, int line);
Type binary_gt_eq_get_type(const Type& left, const Type& right, int line);
Type binary_lt_eq_get_type(const Type& left, const Type& right, int line);
Type binary_in_get_type(const Type& left, const Type& right, int line);
