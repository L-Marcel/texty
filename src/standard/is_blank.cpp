#include <string>

using namespace std;

bool is_blank(const string in) {
  return in.find_first_not_of(" \t\n\v\f\r") == string::npos;
};
