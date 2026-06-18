#include "../core.h"

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