#pragma once
#include "../../../helpers/numeric.hpp"
#include "../../../helpers/pointer.hpp"
#include "../unary.hpp"

Type unary_minus_get_type(const Type& node, int line);
Type unary_not_get_type(const Type& node, int line);
Type unary_rev_get_type(const Type& node, int line);
Type unary_ref_get_type(const Type& node, int line);
Type unary_deref_get_type(const Type& node, int line);
Type unary_increment_get_type(const Type& node, int line);
Type unary_decrement_get_type(const Type& node, int line);
