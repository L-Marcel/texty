#pragma once
#include <stdexcept>
#include <string>

using namespace std;

struct error : public runtime_error {
  error(const string& message, int line);
  error(const string& message);
};