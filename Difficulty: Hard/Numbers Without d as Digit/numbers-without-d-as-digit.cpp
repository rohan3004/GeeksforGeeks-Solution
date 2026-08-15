#include <string>
#include <vector>

class Solution {
    int memo[15][2][2];
    std::string s;
    int D;

    int solve(int idx, int tight, int zero) {
        // Base Case: We successfully reached the end of the digit sequence
        if (idx == s.length()) {
            return 1;
        }

        // Return pre-calculated result to save time
        if (memo[idx][tight][zero] != -1) {
            return memo[idx][tight][zero];
        }

        // The maximum digit we can place at the current index
        int limit = tight ? s[idx] - '0' : 9;
        int ans = 0;

        for (int i = 0; i <= limit; i++) {
            // Check if the current digit 'i' is the restricted digit 'D'
            if (i == D) {
                // We allow it ONLY if D is 0 AND we are still currently forming leading zeroes.
                if (D == 0 && zero == 1) {
                    // Leading zeros are valid
                } else {
                    continue; // Skip restricted digit
                }
            }

            // Move to the next digit
            ans += solve(idx + 1, tight && (i == limit), zero && (i == 0));
        }

        return memo[idx][tight][zero] = ans;
    }

public:
    int countWithout(int n, int d) {
        if (n == 0) return 0;

        s = std::to_string(n);
        D = d;

        // Initialize the 3D memoization array with -1
        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    memo[i][j][k] = -1;
                }
            }
        }

        // Solve evaluating from index 0. 
        // Initial tight bound is true. Initial zero bound is true.
        // We subtract 1 at the end to exclude '0' as valid configuration since the range strictly starts from 1.
        return solve(0, 1, 1) - 1;
    }
};