#include "core.h"

// TODO - Melhorar essas funções
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
  if (result == NULL) exit(1);

  snprintf(result, len + 1, "%0*.*f", total_width, (int)right, value);
  return result;
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
  if (result == NULL) exit(1);

  snprintf(result, len + 1, "%0*.*lf", total_width, (int)right, value);
  return result;
};

char* float_to_string(float value) { return txy_float_decimals(value, 0, 6); };

char* double_to_string(double value) {
  return txy_double_decimals(value, 0, 6);
};

char* int_to_string(int32_t value) {
  int len = snprintf(NULL, 0, "%d", value);
  char* result = (char*)malloc(len + 1);
  if (result == NULL) exit(1);

  snprintf(result, len + 1, "%d", value);
  return result;
};

char* long_to_string(int64_t value) {
  int len = snprintf(NULL, 0, "%lld", (long long)value);
  char* result = (char*)malloc(len + 1);
  if (result == NULL) exit(1);

  snprintf(result, len + 1, "%lld", (long long)value);
  return result;
};

char* byte_to_string(uint8_t value) {
  int len = snprintf(NULL, 0, "%u", (unsigned int)value);
  char* result = (char*)malloc(len + 1);
  if (result == NULL) exit(1);

  snprintf(result, len + 1, "%u", (unsigned int)value);
  return result;
};

char* char_to_string(char value) {
  char* result = (char*)malloc(2);
  if (result == NULL) exit(1);

  result[0] = value;
  result[1] = '\0';
  return result;
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
  if (result == NULL) exit(1);

copy_string:
  if (i == len) goto end_string;
  result[i] = value[i];
  i = i + 1;
  goto copy_string;

end_string:
  result[len] = '\0';
  return result;
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
  if (result == NULL) exit(1);

  snprintf(result, len + 1, "%s", string_value);
  return result;
};
