class Solution {
private:
    int n, m;
    int dr[4] = {0, 0, 1, -1}; // Directions for row: right, left, down, up
    int dc[4] = {1, -1, 0, 0}; // Directions for col

    // Checks if a path exists from (0, 0) to (n-1, m-1)
    // where the absolute difference between any two consecutive cells is <= max_diff.
    bool check(int max_diff, const std::vector<std::vector<int>>& mat) {
        if (n == 0 || m == 0) return true;
        
        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            std::pair<int, int> current = q.front();
            q.pop();
            int r = current.first;
            int c = current.second;

            if (r == n - 1 && c == m - 1) {
                return true; // Reached the destination
            }

            // Explore neighbors
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // Check boundary conditions and visited status
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {
                    
                    // Crucial check: Is the difference <= max_diff?
                    if (std::abs(mat[r][c] - mat[nr][nc]) <= max_diff) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        return false; // Destination not reachable with this max_diff
    }

public:
    int minCostPath(std::vector<std::vector<int>>& mat) {
        n = mat.size();
        if (n == 0) return 0;
        m = mat[0].size();
        if (m == 0) return 0;

        // Binary Search range for the answer (max consecutive difference)
        // Minimum possible value is 0.
        // Maximum possible value is max(mat[i][j]) - min(mat[i][j]), but a safe upper bound is 10^6.
        int low = 0;
        int high = 1000000; // max value of mat[i][j]
        int min_max_diff = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid, mat)) {
                // Path exists with max_diff = mid. Try for a smaller max_diff.
                min_max_diff = mid;
                high = mid - 1;
            } else {
                // Path does not exist. Must allow a larger max_diff.
                low = mid + 1;
            }
        }

        return min_max_diff;
    }
};