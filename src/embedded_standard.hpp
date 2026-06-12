#pragma once

const char* TEXTY_STANDARD_LIBRARY = R"__texty_std__(
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
namespace txy {
template <typename T>
struct array {
  ::std::shared_ptr<::std::vector<T>> ptr;
  array(int size) : ptr(::std::make_shared<::std::vector<T>>(size)) {}
  T& operator[](int index) { return (*ptr)[index]; }
};
};  // namespace txy
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
};
::std::string input_line() {
  ::std::string line;
  ::std::getline(::std::cin, line);
  return line;
};
bool txy_is_empty(const ::std::string in) { return in.empty(); };
bool txy_is_blank(const ::std::string in) {
  return in.find_first_not_of(" \t\n\v\f\r") == ::std::string::npos;
};
void txy_uppercase(::std::string& in) {
  transform(in.begin(), in.end(), in.begin(), ::toupper);
};
void txy_lowercase(::std::string& in) {
  transform(in.begin(), in.end(), in.begin(), ::tolower);
};
void txy_trim_end(::std::string& in) {
  ::std::string::size_type pos = in.find_last_not_of(" \t\n\v\f\r");
  if (pos == ::std::string::npos) pos = in.size();
  in = in.substr(0, pos + 1);
};
void txy_trim_start(::std::string& in) {
  ::std::string::size_type pos = in.find_first_not_of(" \t\n\v\f\r");
  if (pos == ::std::string::npos) pos = 0;
  in = in.substr(pos);
};
void txy_trim(::std::string& in) {
  ::std::string::size_type first = in.find_first_not_of(" \t\n\v\f\r");
  ::std::string::size_type last = in.find_last_not_of(" \t\n\v\f\r");
  if (first == ::std::string::npos) first = 0;
  if (last == ::std::string::npos) last = in.size();
  in = in.substr(first, last + 1);
};
)__texty_std__";
