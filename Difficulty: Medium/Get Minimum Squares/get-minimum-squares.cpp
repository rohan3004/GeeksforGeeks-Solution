#include <vector>
#include <algorithm> // For std::min
#include <climits>   // For INT_MAX

class Solution {
  public:
    int minSquares(int n) {
        // Create a DP array to store results from 0 to n.
        // dp[i] will store the min squares to sum to i.
        // Initialize with a large value (like n+1, since n*1*1 is a valid but max solution)
        std::vector<int> dp(n + 1, n + 1);

        // Base case: 0 needs 0 squares.
        dp[0] = 0;

        // Iterate from 1 up to n
        for (int i = 1; i <= n; i++) {
            // Now, for each dp[i], try subtracting all possible perfect squares
            for (int j = 1; j * j <= i; j++) {
                int square = j * j;
                
                // We can form 'i' by taking 'i - square' and adding 'square'.
                // The cost is 1 (for 'square') + dp[i - square] (the cost for the remainder).
                // We take the minimum of our current dp[i] and this new cost.
                dp[i] = std::min(dp[i], 1 + dp[i - square]);
            }
        }

        // The final answer is stored in dp[n]
        return dp[n];
    }
};