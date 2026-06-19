#include "../core.h"

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