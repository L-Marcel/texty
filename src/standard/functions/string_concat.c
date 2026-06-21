#include "../core.h"

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
