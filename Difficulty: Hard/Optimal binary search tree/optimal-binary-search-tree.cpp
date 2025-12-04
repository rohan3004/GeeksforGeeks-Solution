#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
    // DP table to store results of subproblems
    // dp[i][j] stores the min cost for keys[i...j]
    int dp[105][105];
    
    // To store prefix sums of frequencies for O(1) retrieval
    vector<int> psum;

    // Helper to get sum of frequencies from index i to j
    int getSum(int i, int j) {
        if (i < 0) return 0;
        int sumSub = (i == 0) ? 0 : psum[i - 1];
        return psum[j] - sumSub;
    }

    int solve(int i, int j) {
        // Base case: If no elements in the range, cost is 0
        if (i > j) return 0;
        
        // If already solved, return stored value
        if (dp[i][j] != -1) return dp[i][j];

        // Base case: Single element
        if (i == j) {
            return dp[i][j] = getSum(i, j); // Freq * Level 1
        }

        int minCost = INT_MAX;

        // Try making every key in range [i, j] the root
        for (int k = i; k <= j; k++) {
            // Cost = Cost of Left Subtree + Cost of Right Subtree
            int currentCost = solve(i, k - 1) + solve(k + 1, j);
            
            if (currentCost < minCost) {
                minCost = currentCost;
            }
        }

        // Add the sum of frequencies for the current range [i, j].
        // This effectively adds +1 level to every node in the subtrees
        // relative to the current root k.
        return dp[i][j] = minCost + getSum(i, j);
    }

public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        
        // Initialize DP table with -1
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }

        // Build Prefix Sum array for frequencies
        psum.assign(n, 0);
        psum[0] = freq[0];
        for (int i = 1; i < n; i++) {
            psum[i] = psum[i - 1] + freq[i];
        }

        // Solve for the entire range [0, n-1]
        return solve(0, n - 1);
    }
};