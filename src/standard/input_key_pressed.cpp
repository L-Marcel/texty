#include <termios.h>
#include <unistd.h>

#include <iostream>

using namespace std;

int input_key_pressed() {
  struct termios oldterminal, newterminal;
  // salva o estado atual do terminal.
  tcgetattr(STDIN_FILENO, &oldterminal);
  newterminal = oldterminal;
  newterminal.c_lflag &= (ICANON | ECHO);
  // desativa o buffer de linha (pra não precisar do enter) e o echo (pra não
  // aparecer a tecla digitada).
  tcsetattr(STDIN_FILENO, TCSANOW, &newterminal);

  int caractere = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW,
            &oldterminal);  // Volta pra configuração original.

  return caractere;
}