class Solution {
  public:
    int distinctSubseq(string &str) {
        int n = str.length();
        int MOD = 1e9 + 7;
        
        // dp[i] stores the number of distinct subsequences using prefix of length i
        vector<long long> dp(n + 1);
        
        // Base case: Empty string is one subsequence
        dp[0] = 1; 
        
        // Map to store the last occurred 0-based index of a character
        // Initialize with -1 to indicate character hasn't appeared yet
        vector<int> last(26, -1);
        
        for (int i = 1; i <= n; i++) {
            // Current character (0-based index in string is i-1)
            int charIndex = str[i - 1] - 'a';
            
            // Step 1: Double the previous count
            dp[i] = (dp[i - 1] * 2) % MOD;
            
            // Step 2: If character has appeared before, subtract the duplicates
            // We subtract dp[k] where k is the index where the char last appeared
            if (last[charIndex] != -1) {
                int k = last[charIndex];
                dp[i] = (dp[i] - dp[k] + MOD) % MOD;
            }
            
            // Update the last occurrence of the current character to current index
            last[charIndex] = i - 1;
        }
        
        return dp[n];
    }
};