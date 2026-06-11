#include <algorithm>
#include <string>

using namespace std;

void lowercase(string& in) {
  transform(in.begin(), in.end(), in.begin(), ::tolower);
};
