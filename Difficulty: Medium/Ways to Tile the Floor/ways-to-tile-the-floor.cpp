#include <vector>

class Solution {
public:
    int countWays(int n, int m) {
        const int MOD = 1e9 + 7;
        
        // Base cases
        if (n < m) {
            return 1;
        }
        if (n == m) {
            return 2;
        }
        
        // dp array to store the number of ways to tile an i * m floor
        std::vector<int> dp(n + 1, 0);
        
        // Initialize base cases in the DP array
        for (int i = 1; i < m; ++i) {
            dp[i] = 1;
        }
        dp[m] = 2;
        
        // Fill the DP array using the recurrence relation
        for (int i = m + 1; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - m]) % MOD;
        }
        
        return dp[n];
    }
};