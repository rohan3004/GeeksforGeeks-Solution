class Solution {
public:
    int findWays(int n) {
        // If n is odd, no valid parentheses possible
        if (n % 2 != 0) return 0;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 2; i <= n; i += 2) {
            for (int j = 0; j <= i - 2; j += 2) {
                dp[i] += dp[j] * dp[i - 2 - j];
            }
        }

        return dp[n];
    }
};
