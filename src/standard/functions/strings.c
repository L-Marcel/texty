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

size_t txy_string_length(const char* input) {
  size_t length = 0;
loop_start:
  if (input[length] == '\0') goto loop_end;
  length = length + 1;
  goto loop_start;
loop_end:
  return length;
};

char* txy_align_left(const char* input, int width) {
  size_t len = txy_string_length(input);
  size_t final_width = len > (size_t)width ? len : (size_t)width;
  char* result = (char*)malloc(final_width + 1);
  size_t i = 0;

copy_loop:
  if (i == len) goto pad_loop;
  result[i] = input[i];
  i = i + 1;
  goto copy_loop;

pad_loop:
  if (i == final_width) goto finish;
  result[i] = ' ';
  i = i + 1;
  goto pad_loop;

finish:
  result[final_width] = '\0';
  return result;
};

char* txy_align_right(const char* input, int width) {
  size_t len = txy_string_length(input);
  size_t final_width = len > (size_t)width ? len : (size_t)width;
  char* result = (char*)malloc(final_width + 1);
  size_t pad_len = final_width - len;
  size_t i = 0;

pad_loop:
  if (i == pad_len) goto copy_loop;
  result[i] = ' ';
  i = i + 1;
  goto pad_loop;

copy_loop:
  if (i == final_width) goto finish;
  result[i] = input[i - pad_len];
  i = i + 1;
  goto copy_loop;

finish:
  result[final_width] = '\0';
  return result;
};

char* txy_align_center(const char* input, int width) {
  size_t len = txy_string_length(input);
  size_t final_width = len > (size_t)width ? len : (size_t)width;
  char* result = (char*)malloc(final_width + 1);
  size_t pad_left = (final_width - len) / 2;
  size_t i = 0;

pad_left_loop:
  if (i == pad_left) goto copy_loop;
  result[i] = ' ';
  i = i + 1;
  goto pad_left_loop;

copy_loop:
  if (i == pad_left + len) goto pad_right_loop;
  result[i] = input[i - pad_left];
  i = i + 1;
  goto copy_loop;

pad_right_loop:
  if (i == final_width) goto finish;
  result[i] = ' ';
  i = i + 1;
  goto pad_right_loop;

finish:
  result[final_width] = '\0';
  return result;
};

char* txy_wrap(const char* input, int line_length) {
  size_t len = txy_string_length(input);
  char* result = (char*)malloc(len + 1);
  size_t i = 0;
  size_t col = 0;
  size_t last_space = (size_t)-1;

copy_loop:
  if (i == len) goto finish;
  result[i] = input[i];
  if (result[i] == '\n') goto reset_col;
  if (result[i] == ' ') goto mark_space;
  
  col = col + 1;
  if (col > (size_t)line_length) goto wrap_line;
  
  i = i + 1;
  goto copy_loop;

reset_col:
  col = 0;
  last_space = (size_t)-1;
  i = i + 1;
  goto copy_loop;

mark_space:
  last_space = i;
  col = col + 1;
  if (col > (size_t)line_length) goto wrap_line;
  i = i + 1;
  goto copy_loop;

wrap_line:
  if (last_space == (size_t)-1) goto no_space_wrap;
  result[last_space] = '\n';
  col = i - last_space;
  last_space = (size_t)-1;
  i = i + 1;
  goto copy_loop;

no_space_wrap:
  col = col + 1;
  i = i + 1;
  goto copy_loop;

finish:
  result[len] = '\0';
  return result;
};