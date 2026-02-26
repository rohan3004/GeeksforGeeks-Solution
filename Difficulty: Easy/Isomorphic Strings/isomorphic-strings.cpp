#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // If lengths are different, they cannot be isomorphic
        if (s1.length() != s2.length()) {
            return false;
        }

        // Use two arrays to store the character mappings.
        // Size 256 covers all standard ASCII characters.
        vector<int> map1(256, -1);
        vector<int> map2(256, -1);

        for (int i = 0; i < s1.length(); i++) {
            char c1 = s1[i];
            char c2 = s2[i];

            // If neither character has been mapped yet, create the mapping
            if (map1[c1] == -1 && map2[c2] == -1) {
                map1[c1] = c2;
                map2[c2] = c1;
            } 
            // If a mapping exists, check if it matches the current characters
            else if (map1[c1] != c2 || map2[c2] != c1) {
                return false;
            }
        }

        return true;
    }
};