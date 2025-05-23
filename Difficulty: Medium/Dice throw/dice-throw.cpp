class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) { // for each dice
            for (int j = 1; j <= x; j++) { // for each possible sum
                for (int k = 1; k <= m && k <= j; k++) { // for each face value
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }

        return dp[n][x];
    }
};
