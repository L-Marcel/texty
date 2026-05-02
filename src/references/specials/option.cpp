#include "../references.hpp"

Option::Option() : has_value(false), value(nullptr) {};
Option::Option(Value* value) : has_value(true), value(value) {};