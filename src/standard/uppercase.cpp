#include <algorithm>
#include <string>
using namespace std;
void uppercase(string &in) {
    std::transform(in.begin(), in.end(), in.begin(), ::toupper);
}
