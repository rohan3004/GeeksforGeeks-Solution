class Solution {
private:
    bool solve(int r, int c, int n, vector<vector<int>>& mat, vector<vector<int>>& ans, vector<vector<int>>& dead_end) {
        // Base case: Reached the destination
        if (r == n - 1 && c == n - 1) {
            ans[r][c] = 1;
            return true;
        }
        
        // If current cell is blocked (0) or is a known dead end, return false
        if (mat[r][c] == 0 || dead_end[r][c] == 1) {
            return false;
        }
        
        // Include current cell in the path
        ans[r][c] = 1;
        int max_jump = mat[r][c];
        
        // Try jumps from length 1 to max_jump (Shortest jumps first)
        for (int k = 1; k <= max_jump; ++k) {
            // Priority 1: Move right
            if (c + k < n) {
                if (solve(r, c + k, n, mat, ans, dead_end)) {
                    return true;
                }
            }
            
            // Priority 2: Move down
            if (r + k < n) {
                if (solve(r + k, c, n, mat, ans, dead_end)) {
                    return true;
                }
            }
        }
        
        // If no valid path is found from this cell, backtrack
        ans[r][c] = 0;          // Remove from current path
        dead_end[r][c] = 1;     // Mark as a dead end to avoid future redundant checks
        
        return false;
    }

public:
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // Matrix to store our successful path
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        // Matrix to memoize failed paths (dead ends)
        vector<vector<int>> dead_end(n, vector<int>(n, 0));
        
        // Start DFS from top-left cell
        if (solve(0, 0, n, mat, ans, dead_end)) {
            return ans;
        }
        
        // If no valid path exists
        return {{-1}};
    }
};