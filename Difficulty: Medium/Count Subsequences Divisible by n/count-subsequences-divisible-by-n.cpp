#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubsequences(string& s, int n) {
        int MOD = 1e9 + 7;

        // dp[j] stores the number of subsequences with modulo j
        vector<int> dp(n, 0);

        for (char c : s) {
            int d = c - '0';

            // Create a temporary array to store the next states 
            // initialized with current states (excluding the new digit)
            vector<int> next_dp = dp;

            for (int j = 0; j < n; ++j) {
                if (dp[j] > 0) {
                    // Appending current digit to existing subsequences
                    int new_rem = (j * 10 + d) % n;
                    next_dp[new_rem] = (next_dp[new_rem] + dp[j]) % MOD;
                }
            }

            // Starting a new subsequence with just the current digit
            int single_rem = d % n;
            next_dp[single_rem] = (next_dp[single_rem] + 1) % MOD;

            // Update the main dp array
            dp = next_dp;
        }

        // Return the number of subsequences that are perfectly divisible by n (remainder 0)
        return dp[0];
    }
};