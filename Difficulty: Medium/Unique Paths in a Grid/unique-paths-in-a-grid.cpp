#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // dp[j] will store the number of ways to reach cell (i, j) in the current row i
        vector<int> dp(m, 0);
        
        // Initialize starting cell (0,0)
        // If it's blocked, dp[0] remains 0; otherwise it's 1
        if (grid[0][0] == 0) {
            dp[0] = 1;
        }
        
        // Iterate over each cell row by row
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    // Blocked cell: no ways to reach here
                    dp[j] = 0;
                } else {
                    if (j > 0) {
                        // Add ways from the left cell (same row, column j-1)
                        dp[j] += dp[j - 1];
                    }
                    // If j == 0, dp[j] already carries the number of ways from the cell above (or 1 at start)
                }
            }
        }
        
        // dp[m-1] now holds the total number of ways to reach (n-1, m-1)
        return dp[m - 1];
    }
};
