#include <termios.h>
#include <unistd.h>

#include <iostream>

using namespace std;

int input_key_pressed() {
  struct termios oldterminal, newterminal;

  tcgetattr(STDIN_FILENO, &oldterminal);
  newterminal = oldterminal;
  newterminal.c_lflag &= (ICANON | ECHO);

  tcsetattr(STDIN_FILENO, TCSANOW, &newterminal);

  int caractere = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldterminal);

  return caractere;
}