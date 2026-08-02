#include <vector>

class Solution {
  public:
    int count(int n, int m) {
        // dp[j] will store the number of valid arrays of current length ending with j
        std::vector<int> dp(m + 1, 1);
        
        // Build the arrays length by length, from 2 up to n
        for (int i = 2; i <= n; i++) {
            std::vector<int> next_dp(m + 1, 0);
            
            // For the current length, try ending with j
            for (int j = 1; j <= m; j++) {
                // Check all possible previous endings k
                for (int k = 1; k <= m; k++) {
                    // Valid adjacent pair condition
                    if (j % k == 0 || k % j == 0) {
                        next_dp[j] += dp[k];
                    }
                }
            }
            // Move to the next length by updating dp
            dp = next_dp;
        }
        
        // Sum all the arrays of length n
        int total = 0;
        for (int j = 1; j <= m; j++) {
            total += dp[j];
        }
        
        return total;
    }
};