//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Boundary check and ensure cell is land and not visited
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 'W' || visited[i][j]) 
            return;
        
        // Mark the cell as visited
        visited[i][j] = true;

        // Visit all 8 directions
        dfs(grid, i - 1, j, visited);     // Up
        dfs(grid, i + 1, j, visited);     // Down
        dfs(grid, i, j - 1, visited);     // Left
        dfs(grid, i, j + 1, visited);     // Right
        dfs(grid, i - 1, j - 1, visited); // Top-left
        dfs(grid, i - 1, j + 1, visited); // Top-right
        dfs(grid, i + 1, j - 1, visited); // Bottom-left
        dfs(grid, i + 1, j + 1, visited); // Bottom-right
    }

    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false)); // Track visited cells
        int islandCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'L' && !visited[i][j]) {
                    // Start a new island
                    islandCount++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        
        return islandCount;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends