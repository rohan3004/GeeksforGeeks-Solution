class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        // Create reversed string
        string t = s;
        reverse(t.begin(), t.end());
        
        // dp[i][j] = LCS length of s[0..i-1] and t[0..j-1]
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int lps = dp[n][n];
        return n - lps;
    }
};