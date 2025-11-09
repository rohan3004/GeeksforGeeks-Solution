#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    // 3D DP table for memoization: dp[r1][c1][r2]
    vector<vector<vector<int>>> dp;
    int n;

    /**
     * @param r1 Row of Robot 1
     * @param c1 Column of Robot 1
     * @param r2 Row of Robot 2
     * @param mat The grid
     * @return Maximum chocolates collected from this state to the end
     */
    int solve(int r1, int c1, int r2, vector<vector<int>> &mat) {
        // Calculate c2 based on the state definition (r1 + c1 = r2 + c2)
        int c2 = r1 + c1 - r2;

        // --- Base Cases (Invalid States) ---
        // 1. Check if anyone is out of bounds
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n) {
            return INT_MIN;
        }
        // 2. Check if anyone hit a blocked cell
        if (mat[r1][c1] == -1 || mat[r2][c2] == -1) {
            return INT_MIN;
        }

        // --- Base Case (Successful End) ---
        // If Robot 1 reaches the end, Robot 2 must also be at the end
        if (r1 == n - 1 && c1 == n - 1) {
            return mat[r1][c1];
        }

        // --- Memoization Check ---
        if (dp[r1][c1][r2] != -1) {
            return dp[r1][c1][r2];
        }

        // --- Calculate Chocolates for Current Step ---
        int chocolates = 0;
        if (r1 == r2) {
            // Both robots are on the same cell
            chocolates = mat[r1][c1];
        } else {
            // Robots are on different cells
            chocolates = mat[r1][c1] + mat[r2][c2];
        }

        // --- Transitions (Explore 4 possible next moves) ---
        int f1 = solve(r1 + 1, c1, r2 + 1, mat); // R1: Down, R2: Down
        int f2 = solve(r1 + 1, c1, r2, mat);     // R1: Down, R2: Right
        int f3 = solve(r1, c1 + 1, r2 + 1, mat); // R1: Right, R2: Down
        int f4 = solve(r1, c1 + 1, r2, mat);     // R1: Right, R2: Right

        // Find the best path from the 4 options
        int max_future = max({f1, f2, f3, f4});

        // If max_future is INT_MIN, it means all future paths are blocked
        if (max_future == INT_MIN) {
            return dp[r1][c1][r2] = INT_MIN;
        }

        // Store and return the result for the current state
        return dp[r1][c1][r2] = chocolates + max_future;
    }

public:
    int chocolatePickup(vector<vector<int>> &mat) {
        this->n = mat.size();
        
        // If the starting cell is blocked, no path is possible
        if (mat[0][0] == -1) {
            return 0;
        }

        // Initialize dp table with -1 (meaning "not computed yet")
        dp.resize(n, vector<vector<int>>(n, vector<int>(n, -1)));

        // Start the recursion from the initial state (both robots at 0,0)
        int ans = solve(0, 0, 0, mat);

        // If 'ans' is INT_MIN or any negative number, it means no valid
        // path was found. The problem states to return 0 in this case.
        return max(0, ans);
    }
};