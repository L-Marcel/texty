#include "../core.hpp"

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