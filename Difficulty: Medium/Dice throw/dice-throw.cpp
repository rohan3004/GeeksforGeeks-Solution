#include <vector>

using namespace std;

class Solution {
  public:
    long long noOfWays(int m, int n, int x) {
        // Create a DP table initialized to 0
        // dp[i][j] = number of ways to get sum j with i dice
        vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));

        // Base case: 0 dice can form sum 0 in exactly 1 way
        dp[0][0] = 1;

        // Iterate through each die
        for (int i = 1; i <= n; i++) {
            // Iterate through each possible target sum
            for (int j = 1; j <= x; j++) {
                // Check each face of the current die
                for (int k = 1; k <= m && k <= j; k++) {
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }

        return dp[n][x];
    }
};