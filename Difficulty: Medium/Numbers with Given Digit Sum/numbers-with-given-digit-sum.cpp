#include <vector>

class Solution {
  private:
    int dp[10][82];

    int solve(int n, int sum) {
        // If the remaining sum becomes negative, it's an invalid path
        if (sum < 0) return 0;
        
        // When no digits are left to place, check if the required sum is met
        if (n == 0) return sum == 0 ? 1 : 0;
        
        // Return previously calculated result to avoid redundant computations
        if (dp[n][sum] != -1) return dp[n][sum];
        
        int ans = 0;
        // The remaining digits can be anything from 0 to 9
        for (int i = 0; i <= 9; i++) {
            ans += solve(n - 1, sum - i);
        }
        
        return dp[n][sum] = ans;
    }

  public:
    int countWays(int n, int sum) {
        // A valid n-digit number cannot have a sum less than 1 
        // or greater than 9 * n (if all digits are 9)
        if (sum < 1 || sum > 9 * n) {
            return -1;
        }

        // Initialize memoization table with -1
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 82; ++j) {
                dp[i][j] = -1;
            }
        }

        int totalWays = 0;
        
        // The first digit cannot be 0, so it goes from 1 to 9
        for (int i = 1; i <= 9; i++) {
            totalWays += solve(n - 1, sum - i);
        }

        // If no valid combinations are found, return -1
        return totalWays > 0 ? totalWays : -1;
    }
};