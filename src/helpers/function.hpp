#pragma once
#include "../references/value.hpp"
#include "includes.hpp"

bool check_if_is_varchar_function(const string& name);
string get_varchar_function_types_as_string(const string& name);
vector<Type> get_required_varchar_function_types(const string& name);
Type get_others_varchar_function_types(const string& name);