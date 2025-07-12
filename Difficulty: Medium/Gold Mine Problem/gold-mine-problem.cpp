class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size();        // number of rows
        int m = mat[0].size();     // number of columns
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Fill the last column with original gold values
        for (int i = 0; i < n; i++)
            dp[i][m-1] = mat[i][m-1];

        // Start from second last column to the first
        for (int col = m - 2; col >= 0; col--) {
            for (int row = 0; row < n; row++) {
                int right = dp[row][col+1];
                int up_right = (row > 0) ? dp[row-1][col+1] : 0;
                int down_right = (row < n-1) ? dp[row+1][col+1] : 0;

                dp[row][col] = mat[row][col] + max({right, up_right, down_right});
            }
        }

        // Get the maximum value from the first column
        int max_gold = 0;
        for (int i = 0; i < n; i++) {
            max_gold = max(max_gold, dp[i][0]);
        }

        return max_gold;
    }
};
