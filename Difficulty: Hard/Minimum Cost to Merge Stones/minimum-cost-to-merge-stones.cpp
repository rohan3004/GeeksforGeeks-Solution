#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();

        // 1. Check for the impossible case
        // Each merge operation reduces the pile count by (k - 1).
        // We need to go from 'n' piles to '1' pile, a reduction of (n - 1).
        // Thus, (n - 1) must be a multiple of (k - 1).
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }

        // 2. Create prefix sum array for O(1) range sum queries
        // prefix[i] stores sum of stones[0...i-1]
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + stones[i];
        }
        
        // Helper lambda to get sum of stones[i...j]
        auto getSum = [&](int i, int j) {
            return prefix[j + 1] - prefix[i];
        };

        // 3. Initialize DP table
        // dp[i][j][p] = min cost to merge stones[i...j] into 'p' piles
        // We use a large number (1e9) to represent infinity
        int INF = 1e9;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, INF)));

        // 4. Base Case: len = 1
        // Cost to merge a single pile into 1 pile is 0
        for (int i = 0; i < n; ++i) {
            dp[i][i][1] = 0;
        }

        // 5. Fill DP table for len = 2 to n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;

                // A) "Split" operation: Calculate dp[i][j][p] for p = 2 to k
                for (int p = 2; p <= k; ++p) {
                    // Optimized split point 'm'. We only check 'm' where [i...m]
                    // is mergeable to 1 pile, i.e., (m - i) % (k - 1) == 0.
                    for (int m = i; m < j; m += (k - 1)) {
                        if (dp[i][m][1] != INF && dp[m + 1][j][p - 1] != INF) {
                            dp[i][j][p] = min(dp[i][j][p], dp[i][m][1] + dp[m + 1][j][p - 1]);
                        }
                    }
                }

                // B) "Merge" operation: Calculate dp[i][j][1]
                // This is only possible if we can form 'k' piles from [i...j]
                if (dp[i][j][k] != INF) {
                    dp[i][j][1] = dp[i][j][k] + getSum(i, j);
                }
            }
        }

        // 6. Return the final answer
        // The result will be INF if it was possible but some subproblem wasn't solvable.
        // However, our initial (n-1)%(k-1) check guarantees a solution exists.
        return dp[0][n - 1][1];
    }
};