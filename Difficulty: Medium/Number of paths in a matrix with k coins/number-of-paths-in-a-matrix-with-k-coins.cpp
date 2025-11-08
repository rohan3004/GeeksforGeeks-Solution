#include <vector>
using namespace std;

class Solution {
  public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        // dp[i][j][s] = number of paths from (0,0) to (i,j)
        // that result in a sum of 's'.
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

        // Base Case: Starting cell
        int start_val = mat[0][0];
        if (start_val <= k) {
            dp[0][0][start_val] = 1;
        }

        // Fill the DP table
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // We already handled the base case, so skip
                if (i == 0 && j == 0) continue; 

                int current_coin = mat[i][j];

                for (int s = 0; s <= k; ++s) {
                    // We need to find the sum *before* adding the current cell's coins
                    int prev_sum = s - current_coin;

                    // If prev_sum is valid (not negative)
                    if (prev_sum >= 0) {
                        // 1. Path from above (if we are not in the first row)
                        if (i > 0) {
                            dp[i][j][s] += dp[i - 1][j][prev_sum];
                        }
                        // 2. Path from left (if we are not in the first col)
                        if (j > 0) {
                            dp[i][j][s] += dp[i][j - 1][prev_sum];
                        }
                    }
                }
            }
        }

        // The answer is the number of paths to the bottom-right cell
        // with a sum of exactly k.
        return dp[n - 1][m - 1][k];
    }
};