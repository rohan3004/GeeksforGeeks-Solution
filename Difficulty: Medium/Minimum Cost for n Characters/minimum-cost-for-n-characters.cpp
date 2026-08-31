#include <vector>
#include <algorithm>

class Solution {
public:
    int minCost(int n, int i, int d, int c) {
        // Base case: If we only want 1 character, minimum cost is just 1 insertion.
        if (n == 1) return i;

        // dp[k] will store the minimum cost to get exactly k characters on the screen.
        std::vector<int> dp(n + 1, 0);

        // Cost to obtain 1 character is inserting one time.
        dp[1] = i;

        for (int k = 2; k <= n; ++k) {
            if (k % 2 == 0) {
                // If k is even: We can reach it by adding 1 to (k-1) OR copy-pasting from (k/2)
                dp[k] = std::min(dp[k - 1] + i, dp[k / 2] + c);
            } else {
                // If k is odd: We can reach it by adding 1 to (k-1) OR copy-pasting from (k+1)/2 and deleting 1
                dp[k] = std::min(dp[k - 1] + i, dp[(k + 1) / 2] + c + d);
            }
        }

        return dp[n];
    }
};