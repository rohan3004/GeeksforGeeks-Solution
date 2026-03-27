class Solution {
private:
    int solve(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        // Base case 1: Out of bounds
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) {
            return -1e9; // Return a very small value to invalidate this path
        }
        
        // Base case 2: Reached the last row
        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        // Check memoization table
        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }

        int maxi = -1e9;
        
        // Explore all 9 possible combinations of moves for both robots
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int chocolates = 0;
                
                // If they land on the same cell, add only once
                if (j1 == j2) {
                    chocolates = grid[i][j1];
                } else {
                    chocolates = grid[i][j1] + grid[i][j2];
                }
                
                // Add the result of the recursive call for the next row
                chocolates += solve(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp);
                maxi = max(maxi, chocolates);
            }
        }
        
        // Store and return the result
        return dp[i][j1][j2] = maxi;
    }

public:
    int maxChocolate(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // 3D DP array initialized to -1
        // dp[n][m][m]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        
        // Start from row 0, Robot 1 at col 0, Robot 2 at col m-1
        return solve(0, 0, m - 1, n, m, grid, dp);
    }
};