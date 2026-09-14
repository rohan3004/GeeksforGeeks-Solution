class Solution {
public:
    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        if (n == 0) return -1;
        int m = mat[0].size();
        if (m == 0) return -1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Step 1: Mark unsafe cells adjacent to landmines
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If a landmine is found
                if (mat[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dr[k];
                        int nj = j + dc[k];

                        // Mark adjacent cells that were originally safe (1) as unsafe (-1)
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] == 1) {
                            mat[ni][nj] = -1;
                        }
                    }
                }
            }
        }

        // Step 2: Multi-source BFS from all safe cells in the leftmost column
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 1) {
                // IMPORTANT FIX: Start path length as 1 (counting the starting cell itself)
                q.push({{i, 0}, 1}); 
                mat[i][0] = 2; // Mark as visited 
            }
        }

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int r = curr.first.first;
            int c = curr.first.second;
            int d = curr.second;

            // If we've reached the rightmost column, return the length of path
            if (c == m - 1) return d;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                // If the neighbor is within bounds and is a safe cell
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 1) {
                    mat[nr][nc] = 2; // Mark as visited
                    q.push({{nr, nc}, d + 1});
                }
            }
        }

        // If no safe path is found reaching the last column
        return -1;
    }
};