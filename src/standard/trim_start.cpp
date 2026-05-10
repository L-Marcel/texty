#include <string>
using namespace std;

void trim_start(string &in) {
    string::size_type pos = in.find_first_not_of(" \t\n\v\f\r");
    if (pos == string::npos) pos = 0;
    in = in.substr(pos);
}
