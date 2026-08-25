class Solution {
public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();
        // dp[i] will store the length of the longest consecutive subsequence ending with value i
        vector<int> dp(n + 1, 0);
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            // The longest consecutive subsequence ending at arr[i] is 1 + the one ending at arr[i] - 1
            dp[arr[i]] = dp[arr[i] - 1] + 1;

            // Track the maximum length found so far
            if (dp[arr[i]] > max_len) {
                max_len = dp[arr[i]];
            }
        }

        // The minimum moves will be the total elements minus the longest consecutive subsequence
        return n - max_len;
    }
};