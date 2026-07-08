#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countCoordinates(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        
        // Matrices to keep track of cells that can reach P and Q
        vector<vector<bool>> reachP(n, vector<bool>(m, false));
        vector<vector<bool>> reachQ(n, vector<bool>(m, false));
        
        queue<pair<int, int>> qP, qQ;
        
        // Initialize boundaries for Station P (Top, Left) and Station Q (Bottom, Right)
        for (int i = 0; i < n; i++) {
            qP.push({i, 0});
            reachP[i][0] = true;
            
            qQ.push({i, m - 1});
            reachQ[i][m - 1] = true;
        }
        
        for (int j = 0; j < m; j++) {
            // Check to prevent pushing the corners twice
            if (!reachP[0][j]) {
                qP.push({0, j});
                reachP[0][j] = true;
            }
            if (!reachQ[n - 1][j]) {
                qQ.push({n - 1, j});
                reachQ[n - 1][j] = true;
            }
        }
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        // Helper lambda for BFS
        auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& reach) {
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    
                    // The reverse condition: Next cell must have a GREATER or EQUAL signal
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m 
                        && !reach[nr][nc] && mat[nr][nc] >= mat[r][c]) {
                        
                        reach[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        };
        
        // Run BFS inwards from both boundary sets
        bfs(qP, reachP);
        bfs(qQ, reachQ);
        
        // Count the cells that can reach both
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (reachP[i][j] && reachQ[i][j]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};