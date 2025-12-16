#include <string>
using namespace std;

class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // 1. Check if lengths are equal.
        // If lengths differ, s2 cannot be a rotation of s1.
        if (s1.length() != s2.length()) {
            return false;
        }
        
        // 2. Concatenate s1 with itself.
        string combined = s1 + s1;
        
        // 3. Check if s2 is a substring of the combined string.
        // string::find returns string::npos if the substring is not found.
        if (combined.find(s2) != string::npos) {
            return true;
        }
        
        return false;
    }
};