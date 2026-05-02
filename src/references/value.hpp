#pragma once
#include "includes.hpp"

struct Record;
struct Enum;
struct Pointer;
struct Option;
struct Range;
struct Array;

using UnboundedValue = monostate;
using BoundValue =
    variant<UnboundedValue, uint8_t, int32_t, int64_t, float, double>;

using Value = variant<string, uint8_t, int32_t, int64_t, float, double, bool,
                      Record, Enum, Pointer, Option, Range>;

struct Record {
  // TODO: Definir estrutura dos records
};

struct Enum {
  // TODO: Definir estrutura dos enums
};

struct Array {
  vector<Value> values;
};

struct Range {
  BoundValue left;
  BoundValue right;
  bool inclusive_left;
  bool inclusive_right;
};

struct Option {
  bool has_value;
  Value* value;

  Option(Value* value);
  Option();
};

struct Pointer {
  uint64_t value;
  Type type;
};