#include <string>
using namespace std;

void trim_end(string &in) {
    string::size_type pos = in.find_last_not_of(" \t\n\v\f\r");
    if (pos == string::npos) pos = in.size();
    in = in.substr(0,pos+1);
}
