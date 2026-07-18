class Solution {
public:
    int findWays(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        const int MOD = 1e9 + 7;

        // Step 1: Precompute suffix sum of 1s
        vector<vector<int>> suf(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                suf[i][j] = matrix[i][j] + suf[i + 1][j] + suf[i][j + 1] - suf[i + 1][j + 1];
            }
        }

        // If the entire matrix has fewer than k '1's, impossible to form k pieces
        if (suf[0][0] < k) return 0;

        // Step 2: Precompute the next valid starting row (next_R) and col (next_C)
        vector<vector<int>> next_R(n, vector<int>(m, n));
        for (int j = 0; j < m; ++j) {
            for (int i = n - 2; i >= 0; --i) {
                if (suf[i + 1][j] < suf[i][j]) {
                    next_R[i][j] = i + 1;
                } else {
                    next_R[i][j] = next_R[i + 1][j];
                }
            }
        }

        vector<vector<int>> next_C(n, vector<int>(m, m));
        for (int i = 0; i < n; ++i) {
            for (int j = m - 2; j >= 0; --j) {
                if (suf[i][j + 1] < suf[i][j]) {
                    next_C[i][j] = j + 1;
                } else {
                    next_C[i][j] = next_C[i][j + 1];
                }
            }
        }

        // Step 3: Base case DP setup for k = 1
        vector<vector<int>> prev_dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (suf[i][j] > 0) {
                    prev_dp[i][j] = 1;
                }
            }
        }

        vector<vector<int>> curr_dp(n, vector<int>(m, 0));
        vector<vector<int>> row_sum(n + 1, vector<int>(m, 0));
        vector<vector<int>> col_sum(n, vector<int>(m + 1, 0));

        // Step 4: Run DP for every step up to k
        for (int step = 2; step <= k; ++step) {
            
            // Build the cumulative sums for O(1) state transitions
            for (int j = 0; j < m; ++j) {
                row_sum[n][j] = 0;
                for (int i = n - 1; i >= 0; --i) {
                    row_sum[i][j] = (row_sum[i + 1][j] + prev_dp[i][j]) % MOD;
                }
            }

            for (int i = 0; i < n; ++i) {
                col_sum[i][m] = 0;
                for (int j = m - 1; j >= 0; --j) {
                    col_sum[i][j] = (col_sum[i][j + 1] + prev_dp[i][j]) % MOD;
                }
            }

            // Fill the current DP level
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    // Not enough 1s remaining to support the target segments
                    if (suf[i][j] < step) {
                        curr_dp[i][j] = 0;
                    } else {
                        long long ways = 0;
                        ways = (ways + row_sum[next_R[i][j]][j]) % MOD; // All valid horizontal cuts
                        ways = (ways + col_sum[i][next_C[i][j]]) % MOD; // All valid vertical cuts
                        curr_dp[i][j] = ways;
                    }
                }
            }

            // Shift states up for the next cut iteration
            prev_dp = curr_dp;
        }

        return prev_dp[0][0];
    }
};