class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        // Find the maximum element to bound our DP array size
        int max_val = 0;
        for (int x : arr) {
            if (x > max_val) {
                max_val = x;
            }
        }

        // dp[x] stores the length of the longest valid subsequence ending at value 'x'.
        // Size is max_val + 2 to safely check dp[arr[i] + 1] without out-of-bounds errors.
        vector<int> dp(max_val + 2, 0);
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            int val = arr[i];

            // Check lengths of subsequences ending at val-1 and val+1
            int prev1 = (val - 1 >= 0) ? dp[val - 1] : 0;
            int prev2 = dp[val + 1];

            // The current value extends the best previous subsequence
            dp[val] = max(prev1, prev2) + 1;

            // Track the overall maximum length
            if (dp[val] > max_len) {
                max_len = dp[val];
            }
        }

        return max_len;
    }
};