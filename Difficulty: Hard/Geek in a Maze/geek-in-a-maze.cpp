#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    struct Node {
        int r, c, u;
    };

    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        if (m == 0) return 0;

        // If the starting cell is an obstacle, no cells can be visited
        if (mat[r][c] == '#') return 0;

        // Distance array tracking the minimum UP moves to reach each cell
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        deque<Node> dq;

        dist[r][c] = 0;
        dq.push_back({r, c, 0});

        // Direction vectors: 0: Up, 1: Down, 2: Left, 3: Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!dq.empty()) {
            Node curr = dq.front();
            dq.pop_front();

            // Skip processing if we've already found a strictly better path earlier
            if (curr.u > dist[curr.r][curr.c]) continue;

            for (int i = 0; i < 4; i++) {
                int nr = curr.r + dr[i];
                int nc = curr.c + dc[i];

                // Ensure boundary conditions are met and it's an empty space
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == '.') {
                    int weight = (i == 0) ? 1 : 0;          // Only UP move costs 1
                    int next_u = curr.u + weight;           // Total UP moves for next step
                    int next_d = next_u + (nr - r);         // Mathematically derived DOWN moves

                    // Proceed only if the updated counts are within budget
                    if (next_u <= u && next_d <= d) {
                        // 0-1 BFS Relaxation
                        if (next_u < dist[nr][nc]) {
                            dist[nr][nc] = next_u;
                            if (weight == 1) {
                                dq.push_back({nr, nc, next_u});
                            } else {
                                dq.push_front({nr, nc, next_u});
                            }
                        }
                    }
                }
            }
        }

        // Count all the uniquely distinct visited valid cells
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dist[i][j] != 1e9) {
                    ans++;
                }
            }
        }

        return ans;
    }
};