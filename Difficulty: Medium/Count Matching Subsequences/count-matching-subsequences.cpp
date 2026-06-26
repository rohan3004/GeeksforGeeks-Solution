#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countWays(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        int MOD = 1e9 + 7;
        
        // If the target string is longer than the source, it's impossible
        if (m > n) return 0;
        
        // dp[j] will store the number of ways to form the prefix of s2 of length j
        vector<int> dp(m + 1, 0);
        
        // Base case: An empty string s2 can be formed in exactly 1 way 
        // (by deleting all characters from s1)
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            // Traverse backwards to avoid overwriting states from the previous step
            for (int j = m; j >= 1; j--) {
                if (s1[i - 1] == s2[j - 1]) {
                    // If characters match, we can either:
                    // 1. Include this character (dp[j - 1])
                    // 2. Exclude this character (dp[j])
                    dp[j] = (dp[j] + dp[j - 1]) % MOD;
                }
                // If they don't match, dp[j] remains the same (we exclude s1[i-1])
            }
        }
        
        return dp[m];
    }
};