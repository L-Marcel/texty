#pragma once
#include <stdexcept>
#include <string>

struct error : public std::runtime_error {
  error(const std::string& message, int line);
};