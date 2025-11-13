#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        // 1. Initial check: Lengths must add up.
        if (n1 + n2 != n3) {
            return false;
        }

        // 2. Create DP table. dp[i][j] means:
        // is s3[0...i+j-1] an interleaving of
        // s1[0...i-1] and s2[0...j-1]?
        // Size is (n1+1) x (n2+1) to include the empty string case.
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));

        // 3. Base Case:
        // An empty s3 is an interleaving of two empty strings.
        dp[0][0] = true;

        // 4. Initialize first column (using only s1)
        // Check if s1 is a prefix of s3
        for (int i = 1; i <= n1; ++i) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }

        // 5. Initialize first row (using only s2)
        // Check if s2 is a prefix of s3
        for (int j = 1; j <= n2; ++j) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        // 6. Fill the rest of the DP table
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                // The character we are trying to match in s3
                char s3_char = s3[i + j - 1];

                // Option 1: The character came from s1
                // Check if the state *before* taking this char was true
                // AND if the character from s1 matches.
                bool from_s1 = dp[i - 1][j] && (s1[i - 1] == s3_char);

                // Option 2: The character came from s2
                // Check if the state *before* taking this char was true
                // AND if the character from s2 matches.
                bool from_s2 = dp[i][j - 1] && (s2[j - 1] == s3_char);

                // We can reach this state if *either* path is valid.
                dp[i][j] = from_s1 || from_s2;
            }
        }

        // 7. The final answer is in the bottom-right corner.
        return dp[n1][n2];
    }
};