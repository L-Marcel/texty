#include "string.hpp"

string repeat(const string& str, size_t size) {
  if (size == 0 || str.empty()) return "";

  string result;
  result.reserve(str.size() * size);
  for (size_t i = 0; i < size; ++i) {
    result += str;
  };

  return result;
};