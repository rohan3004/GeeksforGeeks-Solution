class Solution {
private:
    int max_len;

    void dfs(vector<vector<int>>& mat, int x, int y, int xd, int yd, int steps, vector<vector<bool>>& vis) {
        // If we reach the destination, update max_len and return
        if (x == xd && y == yd) {
            max_len = max(max_len, steps);
            return;
        }

        // Mark the current cell as visited
        vis[x][y] = true;

        // Direction arrays for moving up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int n = mat.size();
        int m = mat[0].size();

        // Explore all 4 adjacent cells
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Check boundaries, traversability, and whether it's unvisited
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 1 && !vis[nx][ny]) {
                dfs(mat, nx, ny, xd, yd, steps + 1, vis);
            }
        }

        // Backtrack: unmark the cell so it can be used in other paths
        vis[x][y] = false;
    }

public:
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // Base case: if start or end cell is blocked
        if (mat[xs][ys] == 0 || mat[xd][yd] == 0) {
            return -1;
        }

        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        max_len = -1; // Initialize to -1 to handle unreachable cases naturally
        
        dfs(mat, xs, ys, xd, yd, 0, vis);

        return max_len;
    }
};