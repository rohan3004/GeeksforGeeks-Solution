#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSum(int n) {
        // Base case: if n is 0, the maximum sum is 0
        if (n == 0) {
            return 0;
        }
        
        // dp[i] will store the maximum sum we can get for the number i
        std::vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            // Calculate the sum if we break the current number 'i'
            int breakSum = dp[i / 2] + dp[i / 3] + dp[i / 4];
            
            // Take the maximum of not breaking it (i) vs breaking it (breakSum)
            dp[i] = std::max(i, breakSum);
        }
        
        return dp[n];
    }
};