#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeSpaces(string& s) {
        // Shift all non-space characters to the front, then erase the leftover tail
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        return s;
    }
};