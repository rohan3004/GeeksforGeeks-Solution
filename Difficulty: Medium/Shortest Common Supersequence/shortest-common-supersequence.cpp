#include <string>
#include <vector>
#include <algorithm> // For max()

using namespace std;

class Solution {
  public:
    /**
     * Finds the length of the Longest Common Subsequence (LCS)
     * of two strings.
     */
    int lcs(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();

        // dp[i][j] will store the length of the LCS of
        // s1[0...i-1] and s2[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // Case 1: The characters match
                if (s1[i - 1] == s2[j - 1]) {
                    // This character is part of the LCS, so we add 1
                    // to the LCS of the strings before this character.
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                // Case 2: The characters do not match
                else {
                    // The LCS is the best (maximum) we can get by
                    // either excluding the character from s1 or from s2.
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The length of the LCS of the full strings is in the bottom-right cell
        return dp[m][n];
    }

    int minSuperSeq(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();
        
        // Find the length of the Longest Common Subsequence
        int lcsLength = lcs(s1, s2);
        
        // Apply the formula: len(s1) + len(s2) - len(LCS)
        return m + n - lcsLength;
    }
};