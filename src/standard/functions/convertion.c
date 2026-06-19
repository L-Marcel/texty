#include "../core.h"

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
