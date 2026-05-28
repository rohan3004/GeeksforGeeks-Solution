#include <string>
#include <vector>

using namespace std;

class Solution {
    // Helper function for top-down DP
    int solve(int idx, int prevSum, string &s, vector<vector<int>> &memo) {
        // Base case: If we've reached the end of the string, it's a valid grouping
        if (idx == s.size()) {
            return 1;
        }
        
        // Return pre-calculated result if it exists
        if (memo[idx][prevSum] != -1) {
            return memo[idx][prevSum];
        }

        int ways = 0;
        int currSum = 0;
        
        // Try all possible contiguous substrings starting from 'idx'
        for (int i = idx; i < s.size(); ++i) {
            currSum += (s[i] - '0');
            
            // If the current subgroup's sum is valid, add the ways from the remaining string
            if (currSum >= prevSum) {
                ways += solve(i + 1, currSum, s, memo);
            }
        }
        
        // Save to memo and return
        return memo[idx][prevSum] = ways;
    }

public:
    int validGroups(string &s) {
        int n = s.size();
        
        // The maximum possible sum of any sub-group is 100 * 9 = 900.
        // We initialize a 2D vector for memoization: dp[index][prevSum]
        vector<vector<int>> memo(n, vector<int>(905, -1));
        
        // Start from index 0 with a previous sum of 0
        return solve(0, 0, s, memo);
    }
};