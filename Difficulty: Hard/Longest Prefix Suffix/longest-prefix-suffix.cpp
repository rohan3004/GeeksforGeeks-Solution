#include <string>
#include <vector>

class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.length();
        // A single character or empty string has no proper prefix/suffix.
        if (n < 2) {
            return 0;
        }

        // lps[i] will store the length of the longest proper prefix of s[0..i]
        // which is also a suffix of s[0..i].
        std::vector<int> lps(n, 0);

        // 'len' stores the length of the previous longest prefix suffix.
        int len = 0;
        
        // 'i' is the index for the current character in the string.
        int i = 1;

        // The loop calculates lps[i] for i from 1 to n-1.
        while (i < n) {
            if (s[i] == s[len]) {
                // If characters match, we can extend the current prefix-suffix.
                len++;
                lps[i] = len;
                i++;
            } else {
                // If characters do not match...
                if (len != 0) {
                    // We fall back to the lps of the previous character in the prefix.
                    // We do not increment i here.
                    len = lps[len - 1];
                } else {
                    // If len is 0, we couldn't find any match.
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // The lps value for the last character of the string is the answer.
        return lps[n - 1];
    }
};