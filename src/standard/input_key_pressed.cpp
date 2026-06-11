#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

#include <iostream>

using namespace std;

int input_key_pressed() {
#ifdef _WIN32
  return _getch();
#else
  struct termios oldterminal, newterminal;

  tcgetattr(STDIN_FILENO, &oldterminal);
  newterminal = oldterminal;
  newterminal.c_lflag &= ~(ICANON | ECHO);

  tcsetattr(STDIN_FILENO, TCSANOW, &newterminal);

  int caractere = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldterminal);

  return caractere;
#endif
}