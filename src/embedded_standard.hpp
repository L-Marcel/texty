#pragma once

const char* TEXTY_STANDARD_LIBRARY = R"__texty_std__(
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>
namespace txy {
using unbounded_value = ::std::monostate;
using bound_value =
    ::std::variant<unbounded_value, ::std::uint8_t, ::std::int32_t,
                   ::std::int64_t, float, double>;
template <typename T>
struct range {
  static_assert(::std::is_same_v<T, ::std::uint8_t> ||
                    ::std::is_same_v<T, ::std::int32_t> ||
                    ::std::is_same_v<T, ::std::int64_t> ||
                    ::std::is_same_v<T, float> || ::std::is_same_v<T, double>,
                "range precisa ter limites numericos");
  bound_value left;
  bound_value right;
  bool left_inclusive;
  bool right_inclusive;
  range()
      : left(T{}),
        right(::std::monostate{}),
        left_inclusive(true),
        right_inclusive(false) {};
  range(T left, T right, bool left_inclusive, bool right_inclusive)
      : left(left),
        right(right),
        left_inclusive(left_inclusive),
        right_inclusive(right_inclusive) {};
  range(unbounded_value left, T right, bool left_inclusive,
        bool right_inclusive)
      : left(left),
        right(right),
        left_inclusive(left_inclusive),
        right_inclusive(right_inclusive) {};
  range(T left, unbounded_value right, bool left_inclusive,
        bool right_inclusive)
      : left(left),
        right(right),
        left_inclusive(left_inclusive),
        right_inclusive(right_inclusive) {};
  range(unbounded_value left, unbounded_value right, bool left_inclusive,
        bool right_inclusive)
      : left(left),
        right(right),
        left_inclusive(left_inclusive),
        right_inclusive(right_inclusive) {};
  bool contains(const bound_value& value) const {
    if (!::std::holds_alternative<T>(value)) return false;
    T v = ::std::get<T>(value);
    if (::std::holds_alternative<T>(this->left)) {
      T l = ::std::get<T>(this->left);
      if (this->left_inclusive ? (v < l) : (v <= l)) return false;
    };
    if (::std::holds_alternative<T>(this->right)) {
      T r = ::std::get<T>(this->right);
      if (this->right_inclusive ? (v > r) : (v >= r)) return false;
    };
    return true;
  };
};
template <typename T>
struct array {
  ::std::shared_ptr<::std::vector<T>> ptr;
  array() : ptr(::std::make_shared<::std::vector<T>>()) {};
  array(::std::initializer_list<T> init)
      : ptr(::std::make_shared<::std::vector<T>>(init)) {};
  template <typename I, typename = ::std::enable_if_t<::std::is_integral_v<I>>>
  array(I size)
      : ptr(::std::make_shared<::std::vector<T>>(
            static_cast<::std::size_t>(size))) {};
  template <typename I, typename = ::std::enable_if_t<::std::is_integral_v<I>>>
  array(I size, ::std::initializer_list<T> init)
      : ptr(::std::make_shared<::std::vector<T>>(init)) {
    ptr->resize(static_cast<::std::size_t>(size));
  };
  template <typename I, typename = ::std::enable_if_t<::std::is_integral_v<I>>>
  T& operator[](I index) {
    return (*ptr)[static_cast<::std::size_t>(index)];
  };
  bool contains(const T& value) const {
    return ::std::find(this->ptr->begin(), this->ptr->end(), value) !=
           this->ptr->end();
  };
  array<T> operator<<(const array<T>& other) const {
    array<T> result;
    result.ptr->reserve(this->ptr->size() + other.ptr->size());
    result.ptr->insert(result.ptr->end(), this->ptr->begin(), this->ptr->end());
    result.ptr->insert(result.ptr->end(), other.ptr->begin(), other.ptr->end());
    return result;
  };
};
template <typename T>
struct option {
  ::std::unique_ptr<T> inner;
  option() : inner(nullptr) {}
  option(T value) : inner(::std::make_unique<T>(::std::move(value))) {};
  option(const option& other)
      : inner(other.inner ? ::std::make_unique<T>(*other.inner) : nullptr) {};
  option& operator=(const option& other) {
    if (this != &other) {
      inner = other.inner ? ::std::make_unique<T>(*other.inner) : nullptr;
    }
    return *this;
  };
  bool is_some() const { return inner != nullptr; };
  bool is_none() const { return inner == nullptr; };
  T unwrap() const {
    if (!inner) {
      throw ::std::runtime_error("tentativa de acessar valor none");
    };
    return *inner;
  };
};
};  // namespace txy
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
void txy_print(const ::std::string in) { ::std::cout << in; };
void txy_println(const ::std::string in) { ::std::cout << in << ::std::endl; };
template <typename... Args>
::std::string txy_format(const ::std::string& in, const Args&... args) {
  return "TODO do format!";
};
template <typename... Args>
::std::string txy_join(const ::std::string& delimiter, const ::std::string& in,
                       const Args&... args) {
  return "TODO do join!";
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
