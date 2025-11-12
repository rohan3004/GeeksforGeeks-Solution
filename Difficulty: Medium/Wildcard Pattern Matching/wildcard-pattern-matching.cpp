#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        int n = txt.size();
        int m = pat.size();

        // dp[j] = whether pat[0...j-1] matches txt[0...i-1] (previous row)
        vector<bool> prev(m + 1, false);
        
        // dp[j] = whether pat[0...j-1] matches txt[0...i-1] (current row)
        vector<bool> curr(m + 1, false);

        // Base case: Empty pattern and empty text match
        prev[0] = true;

        // Base case: Empty text (i=0) and non-empty pattern
        // Only true if the pattern prefix consists of only '*'
        for (int j = 1; j <= m; j++) {
            if (pat[j - 1] == '*') {
                prev[j] = prev[j - 1];
            }
        }

        // Fill the DP table row by row
        for (int i = 1; i <= n; i++) {
            // curr[0] is always false (non-empty text, empty pattern)
            // We re-initialize curr for each new 'i' (row)
            curr[0] = false; 

            for (int j = 1; j <= m; j++) {
                // Case 1: Characters match, or pattern has '?'
                if (pat[j - 1] == '?' || pat[j - 1] == txt[i - 1]) {
                    curr[j] = prev[j - 1];
                }
                // Case 2: Pattern has '*'
                else if (pat[j - 1] == '*') {
                    // Two possibilities:
                    // 1. curr[j-1]: '*' matches zero characters
                    // 2. prev[j]:   '*' matches one or more characters
                    curr[j] = curr[j - 1] || prev[j];
                }
                // Case 3: Mismatch
                else {
                    curr[j] = false;
                }
            }
            // The current row becomes the previous row for the next iteration
            prev = curr; 
        }

        // The final answer is in the last cell of the last computed row
        return prev[m];
    }
};