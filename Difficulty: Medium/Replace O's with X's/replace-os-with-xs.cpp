#include <vector>
using namespace std;

class Solution {
private:
    /**
     * @brief Performs a Depth First Search (DFS) to find all 'O's connected to a boundary.
     * * @param r The current row index.
     * @param c The current column index.
     * @param n The total number of rows.
     * @param m The total number of columns.
     * @param grid The grid of characters.
     */
    void dfs(int r, int c, int n, int m, vector<vector<char>>& grid) {
        // Base cases for stopping the recursion:
        // 1. Out of bounds (row or column)
        // 2. Not an 'O' (it's 'X' or already visited 'S')
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != 'O') {
            return;
        }
        
        // Mark this cell as 'S' (Safe) so we don't visit it again
        // and to identify it as non-surrounded.
        grid[r][c] = 'S';
        
        // Recurse for all 4 adjacent neighbors
        dfs(r + 1, c, n, m, grid); // Down
        dfs(r - 1, c, n, m, grid); // Up
        dfs(r, c + 1, n, m, grid); // Right
        dfs(r, c - 1, n, m, grid); // Left
    }

public:
    /**
     * @brief Replaces all 'O's surrounded by 'X's with 'X'.
     * * @param grid The grid of characters.
     */
    void fill(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return; // Handle empty grid
        int m = grid[0].size();
        
        // --- Step 1: Mark all "safe" 'O's (connected to boundaries) ---
        
        // Check first and last row
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 'O') {
                dfs(0, j, n, m, grid);
            }
            if (grid[n - 1][j] == 'O') {
                dfs(n - 1, j, n, m, grid);
            }
        }
        
        // Check first and last column
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O') {
                dfs(i, 0, n, m, grid);
            }
            if (grid[i][m - 1] == 'O') {
                dfs(i, m - 1, n, m, grid);
            }
        }
        
        // --- Step 2: Flip the 'O's and 'S's ---
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O') {
                    // This 'O' was not reached by boundary DFS, so it's surrounded.
                    grid[i][j] = 'X';
                } else if (grid[i][j] == 'S') {
                    // This was a "safe" 'O', change it back.
                    grid[i][j] = 'O';
                }
            }
        }
    }
};