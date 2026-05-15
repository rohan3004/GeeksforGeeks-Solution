#include <vector>
#include <algorithm>

class Solution {
public:
    int optimalKeys(int n) {
        // If n is 6 or less, the optimal strategy is to just press 'A' n times.
        if (n <= 6) {
            return n;
        }

        // dp[i] will store the maximum number of A's with i keystrokes
        std::vector<int> dp(n + 1, 0);

        // Base cases
        for (int i = 1; i <= 6; i++) {
            dp[i] = i;
        }

        // Calculate the optimal keystrokes for n > 6
        for (int i = 7; i <= n; i++) {
            // Try all possible breakpoints 'j' where we use Ctrl+A, Ctrl+C 
            // and then Ctrl+V for the remaining strokes.
            for (int j = 1; j <= i - 3; j++) {
                dp[i] = std::max(dp[i], dp[j] * (i - j - 1));
            }
        }

        return dp[n];
    }
};