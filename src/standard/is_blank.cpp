#include <string>
using namespace std;

//Provavelmente existe um jeito mais otimizado de fazer isso mas eu vou me preocupar com isso depois
bool is_blank(const string in) {
    return in.find_first_not_of(" \t\n\v\f\r") == string::npos;
}
