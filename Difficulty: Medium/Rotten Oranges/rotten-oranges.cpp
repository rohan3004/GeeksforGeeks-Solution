#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        
        queue<pair<int, int>> q;
        int fresh_count = 0;
        
        // Step 1: Push all rotten oranges to the queue and count fresh oranges
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 2) {
                    q.push({i, j});
                } else if (mat[i][j] == 1) {
                    fresh_count++;
                }
            }
        }
        
        // If there are no fresh oranges to begin with, it takes 0 time
        if (fresh_count == 0) return 0;
        
        int time = 0;
        
        // Direction arrays to easily check up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        // Step 2: Multi-source BFS
        while (!q.empty() && fresh_count > 0) {
            int q_size = q.size();
            
            // Process all oranges that rot at the current time step
            for (int i = 0; i < q_size; ++i) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                // Check all 4 adjacent directions
                for (int dir = 0; dir < 4; ++dir) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    
                    // If the adjacent cell is within bounds and has a fresh orange
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 1) {
                        mat[nx][ny] = 2;       // Mark as rotten
                        fresh_count--;         // Decrement the fresh count
                        q.push({nx, ny});      // Push to queue to rot others in the next minute
                    }
                }
            }
            // Increment time after processing one full level (one minute)
            time++;
        }
        
        // Step 3: Check if there are any fresh oranges left
        return fresh_count == 0 ? time : -1;
    }
};