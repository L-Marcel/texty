#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  TYPE_UNBOUNDED,
  TYPE_U8,
  TYPE_I32,
  TYPE_I64,
  TYPE_F32,
  TYPE_F64
} bound_type_enum;

typedef struct {
  bound_type_enum type;
  union {
    uint8_t u8;
    int32_t i32;
    int64_t i64;
    float f32;
    double f64;
  } value;
} bound_value;

#define DEFINE_ARRAY(TYPE, NAME)                                            \
  typedef struct {                                                          \
    TYPE* pointer;                                                          \
    size_t capacity;                                                        \
  } array_##NAME;                                                           \
                                                                            \
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
  array_##NAME array_##NAME##_from_values(const TYPE* values, size_t count, \
                                          size_t capacity, TYPE fill) {     \
    if (count > capacity) goto error;                                       \
    array_##NAME array;                                                     \
    array.capacity = capacity;                                              \
    array.pointer = (TYPE*)malloc(capacity * sizeof(TYPE));                 \
                                                                            \
    size_t i = 0;                                                           \
                                                                            \
  fill_loop_start:                                                          \
    if (i == count) goto loop_start;                                        \
    array.pointer[i] = values[i];                                           \
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
  skip_free:                                                                \
    array->capacity = 0;                                                    \
  };                                                                        \
                                                                            \
  int array_##NAME##_contains(const array_##NAME* array, TYPE value) {      \
    size_t i = 0;                                                           \
                                                                            \
  loop_start:                                                               \
    if (i == array->capacity) goto loop_end;                                \
    if (array->pointer[i] == value) goto found;                             \
    i = i + 1;                                                              \
    goto loop_start;                                                        \
                                                                            \
  found:                                                                    \
    return 1;                                                               \
                                                                            \
  loop_end:                                                                 \
    return 0;                                                               \
  };

DEFINE_ARRAY(char, char)
DEFINE_ARRAY(char*, string)
DEFINE_ARRAY(uint8_t, bool)
DEFINE_ARRAY(uint8_t, byte)
DEFINE_ARRAY(int32_t, int)
DEFINE_ARRAY(int64_t, long)
DEFINE_ARRAY(float, float)
DEFINE_ARRAY(double, double)