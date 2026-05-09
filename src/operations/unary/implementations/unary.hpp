#pragma once
#include "../../../helpers/numeric.hpp"
#include "../unary.hpp"

Type unary_minus_get_type(const Type& node, int line);
Type unary_not_get_type(const Type& node, int line);
Type unary_rev_get_type(const Type& node, int line);
Type unary_ref_get_type(const Type& node, int line);
