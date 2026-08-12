#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        int MOD = 1e9 + 7;
        
        // DP tables for number of paths and maximum adventure
        vector<vector<long long>> paths(n, vector<long long>(n, 0));
        vector<vector<int>> adv(n, vector<int>(n, 0));

        // Base case: Starting position
        paths[0][0] = 1;
        adv[0][0] = grid[0][0];

        // Process every cell in the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Skip the starting cell since it is already initialized
                if (i == 0 && j == 0) continue;
                
                int current_adv = -1;
                
                // Can we transition from the cell directly above?
                if (i > 0 && (grid[i-1][j] == 2 || grid[i-1][j] == 3) && paths[i-1][j] > 0) {
                    paths[i][j] = (paths[i][j] + paths[i-1][j]) % MOD;
                    current_adv = max(current_adv, adv[i-1][j] + grid[i][j]);
                }
                
                // Can we transition from the cell directly to the left?
                if (j > 0 && (grid[i][j-1] == 1 || grid[i][j-1] == 3) && paths[i][j-1] > 0) {
                    paths[i][j] = (paths[i][j] + paths[i][j-1]) % MOD;
                    current_adv = max(current_adv, adv[i][j-1] + grid[i][j]);
                }
                
                // If the cell is successfully reachable, set its max adventure
                if (paths[i][j] > 0) {
                    adv[i][j] = current_adv;
                }
            }
        }

        // If no valid path to the bottom-right corner exists, safely return zeros
        if (paths[n-1][n-1] == 0) {
            return {0, 0};
        }
        
        return {static_cast<int>(paths[n-1][n-1]), adv[n-1][n-1]};
    }
};