#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Memoization table: dp[mask][current_city]
    // Size is 2^15 rows and 15 columns
    int dp[1 << 15][15];

    int solve(int mask, int pos, int n, vector<vector<int>>& cost) {
        // Base Case: If all cities have been visited (mask has all bits set)
        if (mask == ((1 << n) - 1)) {
            // Return cost to go from current city back to city 0
            return cost[pos][0];
        }

        // If this state is already computed, return the stored result
        if (dp[mask][pos] != -1) {
            return dp[mask][pos];
        }

        int ans = INT_MAX;

        // Try to visit every other city
        for (int nextCity = 0; nextCity < n; nextCity++) {
            // Check if nextCity is NOT visited in the current mask
            if ((mask & (1 << nextCity)) == 0) {
                
                // Recursive call: mark nextCity as visited in mask, change current position
                int newCost = solve(mask | (1 << nextCity), nextCity, n, cost);
                
                // Update minimum cost
                if (newCost != INT_MAX) {
                    ans = min(ans, cost[pos][nextCity] + newCost);
                }
            }
        }

        // Store and return the result
        return dp[mask][pos] = ans;
    }

    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        
        // Initialize DP table with -1
        // (1 << n) gives 2^n
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }

        // Start recursion:
        // mask = 1 (binary ...001) because we start at city 0, so 0th bit is set
        // pos = 0 (current city is 0)
        return solve(1, 0, n, cost);
    }
};