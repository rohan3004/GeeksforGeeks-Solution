#include <vector>

using namespace std;

class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        
        visited[r][c] = true;
        
        // Directions for moving Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // If the neighbor is within bounds, is a 1, and hasn't been visited, traverse it
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !visited[nr][nc]) {
                dfs(nr, nc, grid, visited);
            }
        }
    }

public:
    int cntOnes(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // 1. Traverse top and bottom rows
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1 && !visited[0][j]) {
                dfs(0, j, grid, visited);
            }
            if (grid[n - 1][j] == 1 && !visited[n - 1][j]) {
                dfs(n - 1, j, grid, visited);
            }
        }
        
        // 2. Traverse left and right columns
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !visited[i][0]) {
                dfs(i, 0, grid, visited);
            }
            if (grid[i][m - 1] == 1 && !visited[i][m - 1]) {
                dfs(i, m - 1, grid, visited);
            }
        }
        
        // 3. Count all 1s that were not reached by our boundary DFS
        int trappedCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    trappedCount++;
                }
            }
        }
        
        return trappedCount;
    }
};