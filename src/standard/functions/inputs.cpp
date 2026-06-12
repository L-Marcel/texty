#include "../core.hpp"

::std::int32_t input_key_pressed() {
#ifdef _WIN32
  return static_cast<::std::int32_t>(_getch());
#else
  struct termios oldterminal, newterminal;

  tcgetattr(STDIN_FILENO, &oldterminal);
  newterminal = oldterminal;
  newterminal.c_lflag &= ~(ICANON | ECHO);

  tcsetattr(STDIN_FILENO, TCSANOW, &newterminal);

  ::std::int32_t caractere = static_cast<::std::int32_t>(getchar());

  tcsetattr(STDIN_FILENO, TCSANOW, &oldterminal);

  return caractere;
#endif
};

::std::string input_line() {
  ::std::string line;
  ::std::getline(::std::cin, line);
  return line;
};