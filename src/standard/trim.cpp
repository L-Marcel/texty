#include <string>
using namespace std;

void trim(string &in) {
    string::size_type first = in.find_first_not_of(" \t\n\v\f\r");
    string::size_type last = in.find_last_not_of(" \t\n\v\f\r");
    if (first == string::npos) first = 0;
    if (last == string::npos) last = in.size();
    in = in.substr(first,last+1);
}
