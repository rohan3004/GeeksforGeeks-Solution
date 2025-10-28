#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:
  /**
   * Finds the distance of the nearest 1 for every cell in a binary grid.
   *
   * @param grid The input binary grid.
   * @return A matrix of the same size where each cell contains the minimum
   * distance to the nearest 1.
   */
  vector<vector<int>> nearest(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    // 1. Initialize distance matrix and queue
    // dist[i][j] = -1 means unvisited
    // dist[i][j] = 0 means it's a source (a '1')
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    // 2. Find all sources (1s) and add them to the queue
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          dist[i][j] = 0;
          q.push({i, j});
        }
      }
    }

    // Direction vectors for {up, down, left, right}
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // 3. Perform Multi-Source BFS
    while (!q.empty()) {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();

      // Explore all 4 neighbors
      for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        // Check for valid boundaries and if the cell is unvisited
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == -1) {
          // Mark as visited and set distance
          dist[nr][nc] = dist[r][c] + 1;
          // Add to queue for further exploration
          q.push({nr, nc});
        }
      }
    }

    // 4. Return the completed distance matrix
    return dist;
  }
};