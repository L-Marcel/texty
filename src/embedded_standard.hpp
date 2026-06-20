#pragma once

const char* TEXTY_STANDARD_LIBRARY = R"__texty_std__(
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
char* txy_float_decimals(float value, int64_t left, int64_t right) {
  int total_width;
  int len;
  char* result;
  if (left >= 0) goto check_right;
  left = 0;
check_right:
  if (right >= 0) goto calc_width;
  right = 0;
calc_width:
  if (right > 0) goto has_decimal;
  total_width = (int)(left + right);
  goto format_step;
has_decimal:
  total_width = (int)(left + right + 1);
format_step:
  len = snprintf(NULL, 0, "%0*.*f", total_width, (int)right, value);
  result = (char*)malloc(len + 1);
  if (result == NULL) goto error;
  snprintf(result, len + 1, "%0*.*f", total_width, (int)right, value);
  return result;
error:
  exit(1);
};
char* txy_double_decimals(double value, int64_t left, int64_t right) {
  int total_width;
  int len;
  char* result;
  if (left >= 0) goto check_right;
  left = 0;
check_right:
  if (right >= 0) goto calc_width;
  right = 0;
calc_width:
  if (right > 0) goto has_decimal;
  total_width = (int)(left + right);
  goto format_step;
has_decimal:
  total_width = (int)(left + right + 1);
format_step:
  len = snprintf(NULL, 0, "%0*.*lf", total_width, (int)right, value);
  result = (char*)malloc(len + 1);
  if (result == NULL) goto error;
  snprintf(result, len + 1, "%0*.*lf", total_width, (int)right, value);
  return result;
error:
  exit(1);
};
char* float_to_string(float value) { return txy_float_decimals(value, 0, 6); };
char* double_to_string(double value) {
  return txy_double_decimals(value, 0, 6);
};
char* int_to_string(int32_t value) {
  int len = snprintf(NULL, 0, "%d", value);
  char* result = (char*)malloc(len + 1);
  if (result == NULL) goto error;
  snprintf(result, len + 1, "%d", value);
  return result;
error:
  exit(1);
};
char* long_to_string(int64_t value) {
  int len = snprintf(NULL, 0, "%lld", (long long)value);
  char* result = (char*)malloc(len + 1);
  if (result == NULL) goto error;
  snprintf(result, len + 1, "%lld", (long long)value);
  return result;
error:
  exit(1);
};
char* byte_to_string(uint8_t value) {
  int len = snprintf(NULL, 0, "%u", (unsigned int)value);
  char* result = (char*)malloc(len + 1);
  if (result == NULL) goto error;
  snprintf(result, len + 1, "%u", (unsigned int)value);
  return result;
error:
  exit(1);
};
char* char_to_string(char value) {
  char* result = (char*)malloc(2);
  if (result == NULL) goto error;
  result[0] = value;
  result[1] = '\0';
  return result;
error:
  exit(1);
};
char* string_to_string(const char* value) {
  size_t len = 0;
  char* result;
  size_t i = 0;
calculate_length:
  if (value[len] == '\0') goto alloc_string;
  len = len + 1;
  goto calculate_length;
alloc_string:
  result = (char*)malloc(len + 1);
  if (result == NULL) goto error;
copy_string:
  if (i == len) goto end_string;
  result[i] = value[i];
  i = i + 1;
  goto copy_string;
end_string:
  result[len] = '\0';
  return result;
error:
  exit(1);
};
char* bool_to_string(uint8_t value) {
  const char* string_value;
  int len;
  char* result;
  if (value) goto set_true;
  string_value = "false";
  goto alloc_bool;
set_true:
  string_value = "true";
alloc_bool:
  len = snprintf(NULL, 0, "%s", string_value);
  result = (char*)malloc(len + 1);
  if (result == NULL) goto error;
  snprintf(result, len + 1, "%s", string_value);
  return result;
error:
  exit(1);
};
char* pointer_to_string(void* pointer) {
  char* result;
  int length;
  length = snprintf(NULL, 0, "%p", pointer);
  result = (char*)malloc(length + 1);
  if (result == NULL) goto error;
  snprintf(result, length + 1, "%p", pointer);
  return result;
error:
  exit(1);
};
#define EQUALS(a, b) ((a) == (b))
typedef struct array_string_s array_string;
char* txy_join(const char* delimiter, array_string args);
char* txy_string_concat(const char* a, const char* b);
#define DECLARE_ARRAY(TYPE, NAME)                                           \
  typedef struct array_##NAME##_s {                                         \
    TYPE* pointer;                                                          \
    size_t capacity;                                                        \
  } array_##NAME;                                                           \
  array_##NAME array_##NAME##_create(size_t capacity, TYPE fill);           \
  array_##NAME array_##NAME##_empty();                                      \
  array_##NAME array_##NAME##_from_values(const TYPE* values, size_t count, \
                                          size_t capacity, TYPE fill);      \
  void array_##NAME##_free(array_##NAME* array);                            \
  int array_##NAME##_compare(array_##NAME a, array_##NAME b);               \
  int array_##NAME##_contains(const array_##NAME* array, TYPE value);       \
  TYPE array_##NAME##_get(const array_##NAME* array, size_t index);         \
  array_##NAME array_##NAME##_concat(array_##NAME a,                        \
                                     array_##NAME b);                       \
  char* array_##NAME##_to_string(array_##NAME array);
#define IMPLEMENT_ARRAY(TYPE, NAME, COMPARE_FUNCTION, TO_STRING)            \
  array_##NAME array_##NAME##_create(size_t capacity, TYPE fill) {          \
    array_##NAME array;                                                     \
    array.capacity = capacity;                                              \
    array.pointer = (TYPE*)malloc(capacity * sizeof(TYPE));                 \
                                                                            \
    size_t i = 0;                                                           \
                                                                            \
  loop_start:                                                               \
    if (i == capacity) goto loop_end;                                       \
    array.pointer[i] = fill;                                                \
    i = i + 1;                                                              \
    goto loop_start;                                                        \
                                                                            \
  loop_end:                                                                 \
    return array;                                                           \
  };                                                                        \
                                                                            \
  array_##NAME array_##NAME##_empty() {                                     \
    array_##NAME array;                                                     \
    array.capacity = 0;                                                     \
    array.pointer = NULL;                                                   \
    return array;                                                           \
  };                                                                        \
                                                                            \
  array_##NAME array_##NAME##_from_values(const TYPE* values, size_t count, \
                                          size_t capacity, TYPE fill) {     \
    array_##NAME array;                                                     \
    size_t i = 0;                                                           \
                                                                            \
    if (count > capacity) goto error;                                       \
    array.capacity = capacity;                                              \
    array.pointer = (TYPE*)malloc(capacity * sizeof(TYPE));                 \
                                                                            \
  fill_loop_start:                                                          \
    if (i == count) goto loop_start;                                        \
    array.pointer[i] = (TYPE)values[i];                                     \
    i = i + 1;                                                              \
    goto fill_loop_start;                                                   \
                                                                            \
  loop_start:                                                               \
    if (i == capacity) goto loop_end;                                       \
    array.pointer[i] = fill;                                                \
    i = i + 1;                                                              \
    goto loop_start;                                                        \
                                                                            \
  loop_end:                                                                 \
    return array;                                                           \
                                                                            \
  error:                                                                    \
    exit(1);                                                                \
  };                                                                        \
                                                                            \
  void array_##NAME##_free(array_##NAME* array) {                           \
    if (array->pointer == NULL) goto skip_free;                             \
    free(array->pointer);                                                   \
    array->pointer = NULL;                                                  \
                                                                            \
  skip_free:                                                                \
    array->capacity = 0;                                                    \
  };                                                                        \
                                                                            \
  int array_##NAME##_compare(array_##NAME a, array_##NAME b) {              \
    size_t i = 0;                                                           \
    if (a.capacity != b.capacity) goto not_equals;                          \
                                                                            \
  loop_start:                                                               \
    if (i == a.capacity) goto equals;                                       \
    if (!COMPARE_FUNCTION(a.pointer[i], b.pointer[i])) goto not_equals;     \
    i = i + 1;                                                              \
    goto loop_start;                                                        \
                                                                            \
  equals:                                                                   \
    return 1;                                                               \
                                                                            \
  not_equals:                                                               \
    return 0;                                                               \
  };                                                                        \
                                                                            \
  int array_##NAME##_contains(const array_##NAME* array, TYPE value) {      \
    size_t i = 0;                                                           \
                                                                            \
  loop_start:                                                               \
    if (i == array->capacity) goto loop_end;                                \
    if (COMPARE_FUNCTION(array->pointer[i], value)) goto found;             \
    i = i + 1;                                                              \
    goto loop_start;                                                        \
                                                                            \
  found:                                                                    \
    return 1;                                                               \
                                                                            \
  loop_end:                                                                 \
    return 0;                                                               \
  };                                                                        \
                                                                            \
  TYPE array_##NAME##_get(const array_##NAME* array, size_t index) {        \
    return array->pointer[index];                                           \
  };                                                                        \
                                                                            \
  array_##NAME array_##NAME##_concat(array_##NAME a,                        \
                                     array_##NAME b) {                      \
    array_##NAME result;                                                    \
    result.capacity = a.capacity + b.capacity;                              \
    result.pointer = (TYPE*)malloc(result.capacity * sizeof(TYPE));         \
                                                                            \
    size_t i = 0;                                                           \
    size_t destiny_index = 0;                                               \
                                                                            \
  concat_a_start:                                                           \
    if (i == a.capacity) goto concat_a_end;                                 \
    result.pointer[destiny_index] = a.pointer[i];                           \
    i = i + 1;                                                              \
    destiny_index = destiny_index + 1;                                      \
    goto concat_a_start;                                                    \
                                                                            \
  concat_a_end:                                                             \
    i = 0;                                                                  \
                                                                            \
  concat_b_start:                                                           \
    if (i == b.capacity) goto concat_b_end;                                 \
    result.pointer[destiny_index] = b.pointer[i];                           \
    i = i + 1;                                                              \
    destiny_index = destiny_index + 1;                                      \
    goto concat_b_start;                                                    \
                                                                            \
  concat_b_end:                                                             \
    return result;                                                          \
  };                                                                        \
                                                                            \
  char* array_##NAME##_to_string(array_##NAME array) {                      \
    size_t i = 0;                                                           \
    const char* delimiter = ", ";                                           \
    char* inner_content;                                                    \
    int final_length;                                                       \
    char* result;                                                           \
    array_string elements = array_string_create(array.capacity, (char*)""); \
                                                                            \
  convert_loop:                                                             \
    if (i == array.capacity) goto join_elements;                            \
    elements.pointer[i] = TO_STRING(array.pointer[i]);                      \
    i = i + 1;                                                              \
    goto convert_loop;                                                      \
                                                                            \
  join_elements:                                                            \
    inner_content = txy_join(delimiter, elements);                          \
    final_length = snprintf(NULL, 0, "[%s]", inner_content);                \
    result = (char*)malloc(final_length + 1);                               \
    if (result == NULL) goto error;                                         \
    snprintf(result, final_length + 1, "[%s]", inner_content);              \
    return result;                                                          \
                                                                            \
  error:                                                                    \
    exit(1);                                                                \
  };
#define DECLARE_OPTION(TYPE, NAME)                                \
  typedef struct {                                                \
    uint8_t is_some;                                              \
    TYPE* value;                                                  \
  } option_##NAME;                                                \
  option_##NAME option_##NAME##_none();                           \
  option_##NAME option_##NAME##_some(TYPE val);                   \
  TYPE option_##NAME##_unwrap(const option_##NAME* option);       \
  option_##NAME option_##NAME##_copy(const option_##NAME* other); \
  void option_##NAME##_assign(option_##NAME* destiny,             \
                              const option_##NAME* source);       \
  int option_##NAME##_compare(option_##NAME a, option_##NAME b);  \
  char* option_##NAME##_to_string(option_##NAME option);
#define IMPLEMENT_OPTION(TYPE, NAME, COMPARE_FUNCTION, TO_STRING)  \
  option_##NAME option_##NAME##_none() {                           \
    option_##NAME option;                                          \
    option.is_some = 0;                                            \
    return option;                                                 \
  };                                                               \
                                                                   \
  option_##NAME option_##NAME##_some(TYPE val) {                   \
    option_##NAME option;                                          \
    option.is_some = 1;                                            \
    option.value = (TYPE*)malloc(sizeof(TYPE));                    \
    if (option.value == NULL) goto error;                          \
    *option.value = val;                                           \
    return option;                                                 \
                                                                   \
  error:                                                           \
    exit(1);                                                       \
  };                                                               \
                                                                   \
  int option_##NAME##_is_some(const option_##NAME* option) {       \
    return option->is_some;                                        \
  };                                                               \
                                                                   \
  int option_##NAME##_is_none(const option_##NAME* option) {       \
    if (option->is_some) goto has_value;                           \
    return 1;                                                      \
  has_value:                                                       \
    return 0;                                                      \
  };                                                               \
                                                                   \
  TYPE option_##NAME##_unwrap(const option_##NAME* option) {       \
    if (option->is_some) goto success;                             \
    exit(1);                                                       \
  success:                                                         \
    return *option->value;                                         \
  };                                                               \
                                                                   \
  option_##NAME option_##NAME##_copy(const option_##NAME* other) { \
    option_##NAME option;                                          \
    if (other->is_some) goto copy_some;                            \
    option.is_some = 0;                                            \
    option.value = NULL;                                           \
    goto copy_end;                                                 \
                                                                   \
  copy_some:                                                       \
    option.is_some = 1;                                            \
    option.value = (TYPE*)malloc(sizeof(TYPE));                    \
    if (option.value == NULL) goto error;                          \
    *option.value = *other->value;                                 \
                                                                   \
  copy_end:                                                        \
    return option;                                                 \
                                                                   \
  error:                                                           \
    exit(1);                                                       \
  };                                                               \
                                                                   \
  void option_##NAME##_assign(option_##NAME* destiny,              \
                              const option_##NAME* source) {       \
    if (destiny == source) goto assign_end;                        \
                                                                   \
    if (source->is_some) goto assign_some;                         \
    destiny->is_some = 0;                                          \
    if (destiny->value != NULL) {                                  \
      free(destiny->value);                                        \
      destiny->value = NULL;                                       \
    }                                                              \
    goto assign_end;                                               \
                                                                   \
  assign_some:                                                     \
    destiny->is_some = 1;                                          \
    if (destiny->value != NULL) goto assign_value;                 \
    destiny->value = (TYPE*)malloc(sizeof(TYPE));                  \
    if (destiny->value == NULL) goto error;                        \
                                                                   \
  assign_value:                                                    \
    *destiny->value = *source->value;                              \
                                                                   \
  assign_end:                                                      \
    return;                                                        \
                                                                   \
  error:                                                           \
    exit(1);                                                       \
  };                                                               \
                                                                   \
  int option_##NAME##_compare(option_##NAME a, option_##NAME b) {  \
    if (a.is_some != b.is_some) goto not_equals;                   \
    if (a.is_some) goto check_value;                               \
    goto equals;                                                   \
                                                                   \
  check_value:                                                     \
    if (COMPARE_FUNCTION(*a.value, *b.value)) goto equals;         \
    goto not_equals;                                               \
                                                                   \
  equals:                                                          \
    return 1;                                                      \
                                                                   \
  not_equals:                                                      \
    return 0;                                                      \
  };                                                               \
                                                                   \
  char* option_##NAME##_to_string(option_##NAME option) {          \
    char* result;                                                  \
    char* string;                                                  \
    int length;                                                    \
                                                                   \
    if (option.is_some) goto format_some;                          \
    length = snprintf(NULL, 0, "none");                            \
    result = (char*)malloc(length + 1);                            \
    if (result == NULL) goto error;                                \
    snprintf(result, length + 1, "none");                          \
    return result;                                                 \
                                                                   \
  format_some:                                                     \
    string = TO_STRING(*option.value);                             \
    length = snprintf(NULL, 0, "some(%s)", string);                \
    result = (char*)malloc(length + 1);                            \
    if (result == NULL) goto error;                                \
    snprintf(result, length + 1, "some(%s)", string);              \
    return result;                                                 \
                                                                   \
  error:                                                           \
    exit(1);                                                       \
  };
typedef enum {
  TYPE_UNBOUNDED,
  TYPE_BYTE,
  TYPE_INT,
  TYPE_LONG,
  TYPE_FLOAT,
  TYPE_DOUBLE
} bound_type_enum;
typedef struct {
  bound_type_enum type;
  union {
    uint8_t v_byte;
    int32_t v_int;
    int64_t v_long;
    float v_float;
    double v_double;
  } value;
} bound_value;
#define DEFINE_RANGE(TYPE, NAME, ENUM_TYPE, UNION_FIELD, COMPARE_FUNCTION,     \
                     TO_STRING)                                                \
  typedef struct {                                                             \
    bound_value left;                                                          \
    bound_value right;                                                         \
    uint8_t left_inclusive;                                                    \
    uint8_t right_inclusive;                                                   \
  } range_##NAME;                                                              \
                                                                               \
  range_##NAME range_##NAME##_create(bound_value left, bound_value right,      \
                                     uint8_t left_inclusive,                   \
                                     uint8_t right_inclusive) {                \
    range_##NAME range;                                                        \
    range.left = left;                                                         \
    range.right = right;                                                       \
    range.left_inclusive = left_inclusive;                                     \
    range.right_inclusive = right_inclusive;                                   \
    return range;                                                              \
  };                                                                           \
                                                                               \
  int range_##NAME##_contains(const range_##NAME* range, bound_value val) {    \
    TYPE checked_value;                                                        \
    TYPE left;                                                                 \
    TYPE right;                                                                \
                                                                               \
    if (val.type != ENUM_TYPE) goto not_included;                              \
    checked_value = val.value.UNION_FIELD;                                     \
                                                                               \
    if (range->left.type == TYPE_UNBOUNDED) goto check_right;                  \
    left = range->left.value.UNION_FIELD;                                      \
    if (range->left_inclusive) goto check_left_inclusion;                      \
    if (checked_value <= left) goto not_included;                              \
    goto check_right;                                                          \
                                                                               \
  check_left_inclusion:                                                        \
    if (checked_value < left) goto not_included;                               \
                                                                               \
  check_right:                                                                 \
    if (range->right.type == TYPE_UNBOUNDED) goto included;                    \
    right = range->right.value.UNION_FIELD;                                    \
    if (range->right_inclusive) goto chekc_right_inclusion;                    \
    if (checked_value >= right) goto not_included;                             \
    goto included;                                                             \
                                                                               \
  chekc_right_inclusion:                                                       \
    if (checked_value > right) goto not_included;                              \
                                                                               \
  included:                                                                    \
    return 1;                                                                  \
                                                                               \
  not_included:                                                                \
    return 0;                                                                  \
  };                                                                           \
                                                                               \
  int range_##NAME##_compare(range_##NAME a, range_##NAME b) {                 \
    if (a.left.type != b.left.type) goto not_equals;                           \
    if (a.left.type == TYPE_UNBOUNDED) goto check_left_inclusive;              \
    if (!COMPARE_FUNCTION(a.left.value.UNION_FIELD, b.left.value.UNION_FIELD)) \
      goto not_equals;                                                         \
                                                                               \
  check_left_inclusive:                                                        \
    if (a.left_inclusive != b.left_inclusive) goto not_equals;                 \
    if (a.right.type != b.right.type) goto not_equals;                         \
    if (a.right.type == TYPE_UNBOUNDED) goto check_right_inclusive;            \
    if (!COMPARE_FUNCTION(a.right.value.UNION_FIELD,                           \
                          b.right.value.UNION_FIELD))                          \
      goto not_equals;                                                         \
                                                                               \
  check_right_inclusive:                                                       \
    if (a.right_inclusive != b.right_inclusive) goto not_equals;               \
    goto equals;                                                               \
                                                                               \
  equals:                                                                      \
    return 1;                                                                  \
                                                                               \
  not_equals:                                                                  \
    return 0;                                                                  \
  };                                                                           \
                                                                               \
  char* range_##NAME##_to_string(range_##NAME range) {                         \
    const char* left_brack;                                                    \
    const char* right_brack;                                                   \
    char* left_value;                                                          \
    char* right_value;                                                         \
    char* result;                                                              \
    int length;                                                                \
                                                                               \
    if (range.left_inclusive) goto add_left_inclusive;                         \
    left_brack = "(";                                                          \
    goto check_left_value;                                                     \
                                                                               \
  add_left_inclusive:                                                          \
    left_brack = "[";                                                          \
                                                                               \
  check_left_value:                                                            \
    if (range.left.type == TYPE_UNBOUNDED) goto add_left_infinity;             \
    left_value = TO_STRING(range.left.value.UNION_FIELD);                      \
    goto check_right_brack;                                                    \
                                                                               \
  add_left_infinity:                                                           \
    left_value = string_to_string("-inf");                                     \
                                                                               \
  check_right_brack:                                                           \
    if (range.right_inclusive) goto add_right_inclusive;                       \
    right_brack = ")";                                                         \
    goto check_right_value;                                                    \
  add_right_inclusive:                                                         \
    right_brack = "]";                                                         \
                                                                               \
  check_right_value:                                                           \
    if (range.right.type == TYPE_UNBOUNDED) goto add_right_infinity;           \
    right_value = TO_STRING(range.right.value.UNION_FIELD);                    \
    goto build;                                                                \
  add_right_infinity:                                                          \
    right_value = string_to_string("inf");                                     \
                                                                               \
  build:                                                                       \
    length = snprintf(NULL, 0, "%s%s, %s%s", left_brack, left_value,           \
                      right_value, right_brack);                               \
    result = (char*)malloc(length + 1);                                        \
    if (result == NULL) goto error;                                            \
    snprintf(result, length + 1, "%s%s, %s%s", left_brack, left_value,         \
             right_value, right_brack);                                        \
    return result;                                                             \
                                                                               \
  error:                                                                       \
    exit(1);                                                                   \
  };
DEFINE_RANGE(uint8_t, byte, TYPE_BYTE, v_byte, EQUALS, byte_to_string)
DEFINE_RANGE(int32_t, int, TYPE_INT, v_int, EQUALS, int_to_string)
DEFINE_RANGE(int64_t, long, TYPE_LONG, v_long, EQUALS, long_to_string)
DEFINE_RANGE(float, float, TYPE_FLOAT, v_float, EQUALS, float_to_string)
DEFINE_RANGE(double, double, TYPE_DOUBLE, v_double, EQUALS, double_to_string)
DECLARE_ARRAY(char*, string)
DECLARE_ARRAY(char, char)
DECLARE_ARRAY(uint8_t, bool)
DECLARE_ARRAY(uint8_t, byte)
DECLARE_ARRAY(int32_t, int)
DECLARE_ARRAY(int64_t, long)
DECLARE_ARRAY(float, float)
DECLARE_ARRAY(double, double)
IMPLEMENT_ARRAY(char*, string, EQUALS, string_to_string)
IMPLEMENT_ARRAY(char, char, EQUALS, char_to_string)
IMPLEMENT_ARRAY(uint8_t, bool, EQUALS, bool_to_string)
IMPLEMENT_ARRAY(uint8_t, byte, EQUALS, byte_to_string)
IMPLEMENT_ARRAY(int32_t, int, EQUALS, int_to_string)
IMPLEMENT_ARRAY(int64_t, long, EQUALS, long_to_string)
IMPLEMENT_ARRAY(float, float, EQUALS, float_to_string)
IMPLEMENT_ARRAY(double, double, EQUALS, double_to_string)
DECLARE_OPTION(char, char)
DECLARE_OPTION(char*, string)
DECLARE_OPTION(uint8_t, bool)
DECLARE_OPTION(uint8_t, byte)
DECLARE_OPTION(int32_t, int)
DECLARE_OPTION(int64_t, long)
DECLARE_OPTION(float, float)
DECLARE_OPTION(double, double)
IMPLEMENT_OPTION(char, char, EQUALS, char_to_string)
IMPLEMENT_OPTION(char*, string, EQUALS, string_to_string)
IMPLEMENT_OPTION(uint8_t, bool, EQUALS, bool_to_string)
IMPLEMENT_OPTION(uint8_t, byte, EQUALS, byte_to_string)
IMPLEMENT_OPTION(int32_t, int, EQUALS, int_to_string)
IMPLEMENT_OPTION(int64_t, long, EQUALS, long_to_string)
IMPLEMENT_OPTION(float, float, EQUALS, float_to_string)
IMPLEMENT_OPTION(double, double, EQUALS, double_to_string)
char* txy_format(const char* pattern, array_string args) {
  size_t i = 0, j = 0, arg_index = 0;
  size_t total_length = 0;
  char character;
  char* result;
calculate_length_loop_start:
  character = pattern[i];
  if (character == '\0') goto alloc_result;
  if (character == '%') goto skip_tag_calculate_length;
  total_length = total_length + 1;
  i = i + 1;
  goto calculate_length_loop_start;
skip_tag_calculate_length:
  if (arg_index == args.capacity) goto ignore_extra_calculate;
  j = 0;
count_arg_length:
  if (args.pointer[arg_index][j] == '\0') goto end_arg_length;
  total_length = total_length + 1;
  j = j + 1;
  goto count_arg_length;
end_arg_length:
  arg_index = arg_index + 1;
ignore_extra_calculate:
  i = i + 1;
consume_tag_calculate:
  character = pattern[i];
  if (character == '\0') goto alloc_result;
  if ((character >= 'a' && character <= 'z') ||
      (character >= '0' && character <= '9') || character == ',' ||
      character == ']' || character == '{' || character == '}' ||
      character == '[')
    goto cont_skip_calculate;
  goto calculate_length_loop_start;
cont_skip_calculate:
  i = i + 1;
  goto consume_tag_calculate;
alloc_result:
  result = (char*)malloc(total_length + 1);
  if (result == NULL) goto error;
  i = 0;
  arg_index = 0;
  total_length = 0;
copy_loop:
  character = pattern[i];
  if (character == '\0') goto finish;
  if (character == '%') goto skip_tag_copy;
  result[total_length] = character;
  total_length = total_length + 1;
  i = i + 1;
  goto copy_loop;
skip_tag_copy:
  if (arg_index == args.capacity) goto ignore_extra_copy;
  j = 0;
copy_arg_string:
  if (args.pointer[arg_index][j] == '\0') goto end_arg_copy;
  result[total_length] = args.pointer[arg_index][j];
  total_length = total_length + 1;
  j = j + 1;
  goto copy_arg_string;
end_arg_copy:
  arg_index = arg_index + 1;
ignore_extra_copy:
  i = i + 1;
consume_tag_copy:
  character = pattern[i];
  if (character == '\0') goto finish;
  if ((character >= 'a' && character <= 'z') ||
      (character >= '0' && character <= '9') || character == ',' ||
      character == ']' || character == '{' || character == '}' ||
      character == '[')
    goto cont_skip_copy;
  goto copy_loop;
cont_skip_copy:
  i = i + 1;
  goto consume_tag_copy;
finish:
  result[total_length] = '\0';
  return result;
error:
  exit(1);
};
char* txy_join(const char* delimiter, array_string args) {
  size_t delimiter_length = 0;
  size_t total_length = 0;
  size_t destiny_index = 0;
  size_t i = 0;
  size_t j = 0;
  char* result;
  char* current_string;
calculate_delimiter_length:
  if (delimiter[delimiter_length] == '\0')
    goto calculate_delimiter_length_loop_end;
  delimiter_length = delimiter_length + 1;
  goto calculate_delimiter_length;
calculate_delimiter_length_loop_end:
  if (args.capacity == 0) goto empty;
calculate_append_string_length:
  if (i == args.capacity) goto calculate_append_string_length_end;
  current_string = args.pointer[i];
  j = 0;
calculate_string_length:
  if (current_string[j] == '\0') goto next_str;
  total_length = total_length + 1;
  j = j + 1;
  goto calculate_string_length;
next_str:
  i = i + 1;
  goto calculate_append_string_length;
calculate_append_string_length_end:
  total_length = total_length + (args.capacity - 1) * delimiter_length;
  result = (char*)malloc(total_length + 1);
  if (result == NULL) goto error;
  i = 0;
copy_loop:
  if (i == args.capacity) goto copy_end;
  current_string = args.pointer[i];
  j = 0;
copy_string:
  if (current_string[j] == '\0') goto copy_delimiter_check;
  result[destiny_index] = current_string[j];
  destiny_index = destiny_index + 1;
  j = j + 1;
  goto copy_string;
copy_delimiter_check:
  if (i == args.capacity - 1) goto skip_delim;
  j = 0;
copy_delim:
  if (j == delimiter_length) goto skip_delim;
  result[destiny_index] = delimiter[j];
  destiny_index = destiny_index + 1;
  j = j + 1;
  goto copy_delim;
skip_delim:
  i = i + 1;
  goto copy_loop;
copy_end:
  result[destiny_index] = '\0';
  return result;
empty:
  result = (char*)malloc(1);
  if (result == NULL) goto error;
  result[0] = '\0';
  return result;
error:
  exit(1);
};
char* txy_string_concat(const char* a, const char* b) {
  size_t len_a = 0;
  size_t len_b = 0;
  size_t i = 0;
  size_t destiny_index = 0;
  char* result;
calc_a:
  if (a[len_a] == '\0') goto calc_b;
  len_a = len_a + 1;
  goto calc_a;
calc_b:
  if (b[len_b] == '\0') goto alloc;
  len_b = len_b + 1;
  goto calc_b;
alloc:
  result = (char*)malloc(len_a + len_b + 1);
  if (result == NULL) exit(1);
copy_a:
  if (i == len_a) goto end_a;
  result[destiny_index] = a[i];
  i = i + 1;
  destiny_index = destiny_index + 1;
  goto copy_a;
end_a:
  i = 0;
copy_b:
  if (i == len_b) goto end_b;
  result[destiny_index] = b[i];
  i = i + 1;
  destiny_index = destiny_index + 1;
  goto copy_b;
end_b:
  result[destiny_index] = '\0';
  return result;
};
int32_t txy_key_pressed() {
#ifdef _WIN32
  return (int32_t)_getch();
#else
  struct termios old_terminal, new_terminal;
  int32_t caractere;
  tcgetattr(STDIN_FILENO, &old_terminal);
  new_terminal = old_terminal;
  new_terminal.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_terminal);
  caractere = (int32_t)getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &old_terminal);
  return caractere;
#endif
};
char* txy_input_line() {
  size_t capacity = 64;
  size_t length = 0;
  char* buffer = (char*)malloc(capacity);
  int current_char;
loop_start:
  current_char = getchar();
  if (current_char == EOF) goto loop_end;
  if (current_char == '\n') goto loop_end;
  buffer[length] = (char)current_char;
  length = length + 1;
  if (length < capacity) goto loop_start;
  capacity = capacity * 2;
  buffer = (char*)realloc(buffer, capacity);
  goto loop_start;
loop_end:
  buffer[length] = '\0';
  return buffer;
};
void txy_print(const char* input) { printf("%s", input); };
void txy_println(const char* input) { printf("%s\n", input); };
int txy_is_empty(const char* input) {
  if (input[0] == '\0') goto is_empty;
  return 0;
is_empty:
  return 1;
};
int txy_is_blank(const char* input) {
  size_t i = 0;
  char character;
loop_start:
  character = input[i];
  if (character == '\0') goto is_blank;
  if (character != ' ' && character != '\t' && character != '\n' &&
      character != '\v' && character != '\f' && character != '\r')
    goto is_not_blank;
  i = i + 1;
  goto loop_start;
is_blank:
  return 1;
is_not_blank:
  return 0;
};
void txy_uppercase(char* input) {
  size_t i = 0;
  char character;
loop_start:
  character = input[i];
  if (character == '\0') goto loop_end;
  if (character < 'a') goto skip;
  if (character > 'z') goto skip;
  input[i] = character - 32;
skip:
  i = i + 1;
  goto loop_start;
loop_end:
  return;
};
void txy_lowercase(char* input) {
  size_t i = 0;
  char character;
loop_start:
  character = input[i];
  if (character == '\0') goto loop_end;
  if (character < 'A') goto skip;
  if (character > 'Z') goto skip;
  input[i] = character + 32;
skip:
  i = i + 1;
  goto loop_start;
loop_end:
  return;
};
void txy_trim_end(char* input) {
  size_t end = 0;
  char character;
find_end:
  if (input[end] == '\0') goto end_found;
  end = end + 1;
  goto find_end;
end_found:
  if (end == 0) goto loop_end;
loop_start:
  end = end - 1;
  character = input[end];
  if (character == ' ') goto trim;
  if (character == '\t') goto trim;
  if (character == '\n') goto trim;
  if (character == '\r') goto trim;
  goto loop_end;
trim:
  input[end] = '\0';
  if (end == 0) goto loop_end;
  goto loop_start;
loop_end:
  return;
};
void txy_trim_start(char* input) {
  size_t start = 0;
  size_t i = 0;
  char character;
find_start:
  character = input[start];
  if (character == '\0') goto shift;
  if (character != ' ' && character != '\t' && character != '\n' &&
      character != '\r')
    goto shift;
  start = start + 1;
  goto find_start;
shift:
  if (start == 0) goto loop_end;
loop_start:
  input[i] = input[start + i];
  if (input[i] == '\0') goto loop_end;
  i = i + 1;
  goto loop_start;
loop_end:
  return;
};
void txy_trim(char* input) {
  txy_trim_start(input);
  txy_trim_end(input);
};
int txy_string_contains(const char* text, const char* substr) {
  size_t i = 0;
  size_t j = 0;
  if (substr[0] == '\0') goto found;
outer_loop:
  if (text[i] == '\0') goto not_found;
  j = 0;
inner_loop:
  if (substr[j] == '\0') goto found;
  if (text[i + j] == '\0') goto not_found;
  if (text[i + j] != substr[j]) goto next_i;
  j = j + 1;
  goto inner_loop;
next_i:
  i = i + 1;
  goto outer_loop;
found:
  return 1;
not_found:
  return 0;
};
int32_t txy_pow_int(int32_t base, int32_t exp) {
  int32_t result = 1;
  int32_t current_exp = exp;
loop_start:
  if (current_exp <= 0) goto loop_end;
  result = result * base;
  current_exp = current_exp - 1;
  goto loop_start;
loop_end:
  return result;
};
int64_t txy_pow_long(int64_t base, int64_t exp) {
  int64_t result = 1;
  int64_t current_exp = exp;
loop_start:
  if (current_exp <= 0) goto loop_end;
  result = result * base;
  current_exp = current_exp - 1;
  goto loop_start;
loop_end:
  return result;
};
double txy_exp_double(double x) {
  double sum = 1.0;
  double term = 1.0;
  int32_t i = 1;
loop_start:
  if (i > 30) goto loop_end;
  term = term * x / i;
  sum = sum + term;
  i = i + 1;
  goto loop_start;
loop_end:
  return sum;
};
double txy_ln_double(double x) {
  if (x <= 0.0) return 0.0;
  double y = (x - 1.0) / (x + 1.0);
  double y_squared = y * y;
  double sum = 0.0;
  double term = y;
  int32_t n = 0;
loop_start:
  if (n > 30) goto loop_end;
  sum = sum + term / (2 * n + 1);
  term = term * y_squared;
  n = n + 1;
  goto loop_start;
loop_end:
  return 2.0 * sum;
};
double txy_pow_double(double base, double exp) {
  if (base == 0.0) return 0.0;
  if (exp == 0.0) return 1.0;
  if (exp == (int64_t)exp) {
    double result = 1.0;
    int64_t current_exp = (int64_t)exp;
    if (current_exp < 0) {
      base = 1.0 / base;
      current_exp = -current_exp;
    }
loop_start:
    if (current_exp <= 0) goto loop_end;
    result = result * base;
    current_exp = current_exp - 1;
    goto loop_start;
loop_end:
    return result;
  }
  return txy_exp_double(exp * txy_ln_double(base));
};
float txy_pow_float(float base, float exp) {
  return (float)txy_pow_double((double)base, (double)exp);
};
uint8_t txy_byte_to_byte(uint8_t value) { return value; };
int32_t txy_byte_to_int(uint8_t value) { return (int32_t)value; };
int64_t txy_byte_to_long(uint8_t value) { return (int64_t)value; };
float txy_byte_to_float(uint8_t value) { return (float)value; };
double txy_byte_to_double(uint8_t value) { return (double)value; };
uint8_t txy_byte_to_bool(uint8_t value) {
  if (value != 0) goto max;
  return 0;
max:
  return 1;
};
char txy_byte_to_char(uint8_t value) { return (char)value; };
uint8_t txy_int_to_byte(int32_t value) {
  if (value < 0) goto min;
  if (value > 255) goto max;
  return (uint8_t)value;
min:
  return 0;
max:
  return 255;
};
int32_t txy_int_to_int(int32_t value) { return value; };
int64_t txy_int_to_long(int32_t value) { return (int64_t)value; };
float txy_int_to_float(int32_t value) { return (float)value; };
double txy_int_to_double(int32_t value) { return (double)value; };
uint8_t txy_int_to_bool(int32_t value) {
  if (value != 0) goto max;
  return 0;
max:
  return 1;
};
char txy_int_to_char(int32_t value) { return (char)value; };
uint8_t txy_long_to_byte(int64_t value) {
  if (value < 0) goto min;
  if (value > 255) goto max;
  return (uint8_t)value;
min:
  return 0;
max:
  return 255;
};
int32_t txy_long_to_int(int64_t value) {
  if (value < -2147483648LL) goto min;
  if (value > 2147483647LL) goto max;
  return (int32_t)value;
min:
  return -2147483648LL;
max:
  return 2147483647LL;
};
int64_t txy_long_to_long(int64_t value) { return value; };
float txy_long_to_float(int64_t value) { return (float)value; };
double txy_long_to_double(int64_t value) { return (double)value; };
uint8_t txy_long_to_bool(int64_t value) {
  if (value != 0) goto max;
  return 0;
max:
  return 1;
};
char txy_long_to_char(int64_t value) { return (char)value; };
uint8_t txy_float_to_byte(float value) {
  if (value < 0) goto min;
  if (value > 255.0f) goto max;
  return (uint8_t)value;
min:
  return 0;
max:
  return 255;
};
int32_t txy_float_to_int(float value) {
  if (value <= -2147483648.0f) goto min;
  if (value >= 2147483648.0f) goto max;
  return (int32_t)value;
min:
  return -2147483648;
max:
  return 2147483647;
};
int64_t txy_float_to_long(float value) {
  if (value <= -9223372036854775808.0f) goto min;
  if (value >= 9223372036854775808.0f) goto max;
  return (int64_t)value;
min:
  return -9223372036854775807LL - 1;
max:
  return 9223372036854775807LL;
};
float txy_float_to_float(float value) { return value; };
double txy_float_to_double(float value) { return (double)value; };
uint8_t txy_float_to_bool(float value) {
  if (value != 0.0f) goto max;
  return 0;
max:
  return 1;
};
char txy_float_to_char(float value) { return (char)value; };
uint8_t txy_double_to_byte(double value) {
  if (value < 0) goto min;
  if (value > 255.0) goto max;
  return (uint8_t)value;
min:
  return 0;
max:
  return 255;
};
int32_t txy_double_to_int(double value) {
  if (value <= -2147483648.0) goto min;
  if (value >= 2147483648.0) goto max;
  return (int32_t)value;
min:
  return -2147483648;
max:
  return 2147483647;
};
int64_t txy_double_to_long(double value) {
  if (value <= -9223372036854775808.0) goto min;
  if (value >= 9223372036854775808.0) goto max;
  return (int64_t)value;
min:
  return -9223372036854775807LL - 1;
max:
  return 9223372036854775807LL;
};
float txy_double_to_float(double value) { return (float)value; };
double txy_double_to_double(double value) { return value; };
uint8_t txy_double_to_bool(double value) {
  if (value != 0.0) goto max;
  return 0;
max:
  return 1;
};
char txy_double_to_char(double value) { return (char)value; };
uint8_t txy_bool_to_bool(uint8_t value) { return value; };
char txy_bool_to_char(uint8_t value) { return (char)value; };
uint8_t txy_bool_to_byte(uint8_t value) { return value; };
int32_t txy_bool_to_int(uint8_t value) { return (int32_t)value; };
int64_t txy_bool_to_long(uint8_t value) { return (int64_t)value; };
float txy_bool_to_float(uint8_t value) { return (float)value; };
double txy_bool_to_double(uint8_t value) { return (double)value; };
uint8_t txy_char_to_bool(char value) {
  if (value != 0) goto max;
  return 0;
max:
  return 1;
};
char txy_char_to_char(char value) { return value; };
uint8_t txy_char_to_byte(char value) { return (uint8_t)value; };
int32_t txy_char_to_int(char value) { return (int32_t)value; };
int64_t txy_char_to_long(char value) { return (int64_t)value; };
float txy_char_to_float(char value) { return (float)value; };
double txy_char_to_double(char value) { return (double)value; };
uint8_t txy_string_to_bool(const char* value) {
  if (value[0] != '\0') goto max;
  return 0;
max:
  return 1;
};
char txy_string_to_char(const char* value) { return value[0]; };
uint8_t txy_string_to_byte(const char* value) {
  int32_t v = atoi(value);
  if (v < 0) goto min;
  if (v > 255) goto max;
  return (uint8_t)v;
min:
  return 0;
max:
  return 255;
};
int32_t txy_string_to_int(const char* value) { return (int32_t)atoi(value); };
int64_t txy_string_to_long(const char* value) { return (int64_t)atoll(value); };
float txy_string_to_float(const char* value) { return (float)atof(value); };
double txy_string_to_double(const char* value) { return atof(value); };
)__texty_std__";
