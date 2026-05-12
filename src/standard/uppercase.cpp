#include <algorithm>
#include <string>

using namespace std;

void uppercase(string& in) {
  transform(in.begin(), in.end(), in.begin(), ::toupper);
};
