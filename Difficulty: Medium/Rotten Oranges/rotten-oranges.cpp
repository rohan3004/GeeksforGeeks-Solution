//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& grid) {
            if (grid.empty() || grid[0].empty())
                return 0;
            int rows = grid.size(), cols = grid[0].size();
            
            // Queue for BFS: each element is a pair (row, col)
            queue<pair<int, int>> rottenQueue;
            int freshCount = 0;
            
            // Add all initial rotten oranges to the queue and count the fresh oranges.
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 2) {
                        rottenQueue.push(make_pair(i, j));
                    } else if (grid[i][j] == 1) {
                        freshCount++;
                    }
                }
            }
            
            // If there are no fresh oranges, return 0.
            if (freshCount == 0)
                return 0;
            
            int time = 0;
            // Directions for adjacent cells: up, down, left, right.
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            
            // Process the queue until all possible oranges are rotted.
            while (!rottenQueue.empty()) {
                int currentLevelSize = rottenQueue.size();
                bool rottedThisRound = false;
                
                // Process all the rotten oranges in the current time frame.
                for (int i = 0; i < currentLevelSize; i++) {
                    pair<int, int> cell = rottenQueue.front();
                    rottenQueue.pop();
                    int r = cell.first;
                    int c = cell.second;
                    
                    for (size_t j = 0; j < directions.size(); j++) {
                        int newRow = r + directions[j].first;
                        int newCol = c + directions[j].second;
                        
                        // Check if the cell is valid and contains a fresh orange.
                        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                            grid[newRow][newCol] = 2;      // Rot this fresh orange.
                            rottenQueue.push(make_pair(newRow, newCol));
                            freshCount--;                // Decrement fresh count.
                            rottedThisRound = true;
                        }
                    }
                }
                
                // Increase time only if a new round of rotting occurred.
                if (rottedThisRound)
                    time++;
            }
            
            // If there are still fresh oranges left, return -1.
            return freshCount == 0 ? time : -1;
        }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends