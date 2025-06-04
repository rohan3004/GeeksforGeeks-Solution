class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n = s1.size();
        int m = s2.size();
        int o = s3.size();
        // dp[i][j][k] will hold LCS‐length of
        // s1[0..i-1], s2[0..j-1], s3[0..k-1].
        vector<vector<vector<int>>> dp(
            n+1,
            vector<vector<int>>(m+1, vector<int>(o+1, 0))
        );

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 1; k <= o; k++) {
                    if (s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1]) {
                        dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                    } else {
                        dp[i][j][k] = max({
                            dp[i-1][j][k],
                            dp[i][j-1][k],
                            dp[i][j][k-1]
                        });
                    }
                }
            }
        }
        return dp[n][m][o];
    }
};
