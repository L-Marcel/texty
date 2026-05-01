#pragma once
#include "includes.hpp"

struct Record {};

struct Enum {};

struct Option {
  bool has_value;
  Value* value;
};

struct Pointer {
  uint64_t value;
  Type type;
};

using Void = monostate;
using Value = variant<Void, string, uint8_t, int32_t, int64_t, float, double,
                      bool, Record, Enum, Pointer, Option>;