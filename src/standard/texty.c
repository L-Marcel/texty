#include "core.h"
#include "functions/to_string.c"

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
  array_##NAME array_##NAME##_from_values(TYPE* values, size_t count, \
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
  array_##NAME array_##NAME##_from_values(TYPE* values, size_t count, \
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
    array_string elements;                                                  \
    if (array.pointer != NULL) goto is_not_null;                            \
    return (char*)"null";                                                   \
  is_not_null:                                                              \
    elements = array_string_create(array.capacity, (char*)"");              \
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
    TYPE value;                                                   \
  } option_##NAME;                                                \
  option_##NAME option_##NAME##_none();                           \
  option_##NAME option_##NAME##_some(TYPE val);                   \
  TYPE option_##NAME##_unwrap(const option_##NAME* option);       \
  option_##NAME option_##NAME##_copy(const option_##NAME* other); \
  void option_##NAME##_assign(option_##NAME* destiny,             \
                              const option_##NAME* source);       \
  int option_##NAME##_compare(option_##NAME a, option_##NAME b);  \
  char* option_##NAME##_to_string(option_##NAME option);          \
  void option_##NAME##_free(option_##NAME* option);               \
                                                                  \
  typedef struct {                                                \
    uint8_t is_some;                                              \
    TYPE* value;                                                  \
  } option_##NAME##_ptr;                                          \
  option_##NAME##_ptr option_##NAME##_ptr_none();                 \
  option_##NAME##_ptr option_##NAME##_ptr_some(TYPE val);         \
  TYPE option_##NAME##_ptr_unwrap(const option_##NAME##_ptr* option); \
  option_##NAME##_ptr option_##NAME##_ptr_copy(const option_##NAME##_ptr* other); \
  void option_##NAME##_ptr_assign(option_##NAME##_ptr* destiny,   \
                                  const option_##NAME##_ptr* source); \
  int option_##NAME##_ptr_compare(option_##NAME##_ptr a, option_##NAME##_ptr b); \
  char* option_##NAME##_ptr_to_string(option_##NAME##_ptr option);

#define DECLARE_OPTION_PTR(TYPE, NAME)                            \
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
  char* option_##NAME##_to_string(option_##NAME option);          \
  void option_##NAME##_free(option_##NAME* option);

#define IMPLEMENT_OPTION(TYPE, NAME, COMPARE_FUNCTION, TO_STRING)  \
  option_##NAME option_##NAME##_none() {                           \
    option_##NAME option = {0};                                    \
    option.is_some = 0;                                            \
    return option;                                                 \
  };                                                               \
                                                                   \
  option_##NAME option_##NAME##_some(TYPE val) {                   \
    option_##NAME option;                                          \
    option.is_some = 1;                                            \
    option.value = val;                                            \
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
    return option->value;                                          \
  };                                                               \
                                                                   \
  option_##NAME option_##NAME##_copy(const option_##NAME* other) { \
    option_##NAME option;                                          \
    option.is_some = other->is_some;                               \
    if (other->is_some) goto define;                               \
    return option;                                                 \
  define:                                                          \
    option.value = other->value;                                   \
    return option;                                                 \
  };                                                               \
                                                                   \
  void option_##NAME##_assign(option_##NAME* destiny,              \
                              const option_##NAME* source) {       \
    destiny->is_some = source->is_some;                            \
    if (source->is_some) goto define;                              \
    return;                                                        \
  define:                                                          \
    destiny->value = source->value;                                \
  };                                                               \
                                                                   \
  int option_##NAME##_compare(option_##NAME a, option_##NAME b) {  \
    if (a.is_some != b.is_some) goto not_equals;                   \
    if (a.is_some) goto check_value;                               \
    goto equals;                                                   \
                                                                   \
  check_value:                                                     \
    if (COMPARE_FUNCTION(a.value, b.value)) goto equals;           \
    goto not_equals;                                               \
                                                                   \
  equals:                                                          \
    return 1;                                                      \
                                                                   \
  not_equals:                                                      \
    return 0;                                                      \
  };                                                               \
                                                                   \
  void option_##NAME##_free(option_##NAME* option) {               \
    option->is_some = 0;                                           \
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
    string = TO_STRING(option.value);                              \
    length = snprintf(NULL, 0, "some(%s)", string);                \
    result = (char*)malloc(length + 1);                            \
    if (result == NULL) goto error;                                \
    snprintf(result, length + 1, "some(%s)", string);              \
    return result;                                                 \
                                                                   \
  error:                                                           \
    exit(1);                                                       \
  };

#define IMPLEMENT_OPTION_POINTER(TYPE, NAME, COMPARE_FUNCTION, TO_STRING) \
  option_##NAME option_##NAME##_none() {                           \
    option_##NAME option = {0};                                    \
    option.is_some = 0;                                            \
    option.value = NULL;                                           \
    return option;                                                 \
  };                                                               \
                                                                   \
  option_##NAME option_##NAME##_some(TYPE val) {                   \
    option_##NAME option;                                          \
    option.is_some = 1;                                            \
    option.value = (TYPE*)malloc(sizeof(TYPE));                    \
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
    option.is_some = other->is_some;                               \
    if (!other->is_some) goto is_none;                             \
    option.value = (TYPE*)malloc(sizeof(TYPE));                    \
    *option.value = *other->value;                                 \
    goto done;                                                     \
  is_none:                                                         \
    option.value = NULL;                                           \
  done:                                                            \
    return option;                                                 \
  };                                                               \
                                                                   \
  void option_##NAME##_assign(option_##NAME* destiny,              \
                              const option_##NAME* source) {       \
    destiny->is_some = source->is_some;                            \
    if (!source->is_some) goto done;                               \
    if (destiny->value != NULL) goto assign_value;                 \
    destiny->value = (TYPE*)malloc(sizeof(TYPE));                  \
  assign_value:                                                    \
    *destiny->value = *source->value;                              \
  done:                                                            \
    return;                                                        \
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
  void option_##NAME##_free(option_##NAME* option) {               \
    if (!option->is_some) goto skip_free;                          \
    if (option->value == NULL) goto skip_free;                     \
    free(option->value);                                           \
    option->value = NULL;                                          \
  skip_free:                                                       \
    option->is_some = 0;                                           \
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
    if (result == NULL) goto error_str;                            \
    snprintf(result, length + 1, "none");                          \
    return result;                                                 \
                                                                   \
  format_some:                                                     \
    string = TO_STRING(*option.value);                             \
    length = snprintf(NULL, 0, "some(%s)", string);                \
    result = (char*)malloc(length + 1);                            \
    if (result == NULL) goto error_str;                            \
    snprintf(result, length + 1, "some(%s)", string);              \
    return result;                                                 \
                                                                   \
  error_str:                                                       \
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
  range_##NAME range_##NAME##_default() {                                      \
    range_##NAME range;                                                        \
    range.left.type = TYPE_UNBOUNDED;                                          \
    range.right.type = TYPE_UNBOUNDED;                                         \
    range.left_inclusive = 0;                                                  \
    range.right_inclusive = 0;                                                 \
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