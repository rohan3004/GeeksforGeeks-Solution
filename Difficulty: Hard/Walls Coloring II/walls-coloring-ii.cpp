#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        
        // Edge Case: If there is more than 1 wall but only 1 color,
        // it's impossible to paint without adjacency conflict.
        if (k == 1 && n > 1) return -1; 
        
        // Variables to track the minimums of the previous row (wall i-1)
        int prev_min1 = INT_MAX;      // Smallest cost
        int prev_min2 = INT_MAX;      // Second smallest cost
        int prev_min1_idx = -1;       // Color index of the smallest cost

        // Initialize with the first wall (row 0)
        for (int j = 0; j < k; j++) {
            if (costs[0][j] < prev_min1) {
                prev_min2 = prev_min1;
                prev_min1 = costs[0][j];
                prev_min1_idx = j;
            } else if (costs[0][j] < prev_min2) {
                prev_min2 = costs[0][j];
            }
        }

        // Iterate through the remaining walls
        for (int i = 1; i < n; i++) {
            // Variables for the current row (wall i)
            int curr_min1 = INT_MAX;
            int curr_min2 = INT_MAX;
            int curr_min1_idx = -1;

            for (int j = 0; j < k; j++) {
                int current_cost = costs[i][j];

                // If the current color j is the same as the one used for the
                // minimum cost of the previous wall, we must use the second min.
                // Otherwise, we use the absolute minimum.
                if (j == prev_min1_idx) {
                    current_cost += prev_min2;
                } else {
                    current_cost += prev_min1;
                }

                // Update min1 and min2 for the current row
                if (current_cost < curr_min1) {
                    curr_min2 = curr_min1;
                    curr_min1 = current_cost;
                    curr_min1_idx = j;
                } else if (current_cost < curr_min2) {
                    curr_min2 = current_cost;
                }
            }

            // Move current values to previous for the next iteration
            prev_min1 = curr_min1;
            prev_min2 = curr_min2;
            prev_min1_idx = curr_min1_idx;
        }

        return prev_min1;
    }
};