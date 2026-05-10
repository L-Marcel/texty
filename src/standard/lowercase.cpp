#include <algorithm>
#include <string>
using namespace std;
void lowercase(string &in) {
    std::transform(in.begin(), in.end(), in.begin(), ::tolower);
}
