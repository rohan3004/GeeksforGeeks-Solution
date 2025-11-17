class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        
        // Initialize DP array. 
        // At minimum, the max sum ending at i is the element itself.
        vector<int> dp = arr;
        
        // Variable to store the global maximum sum
        int overallMax = 0;
        
        // Iterate through every element
        for (int i = 0; i < n; i++) {
            // Check all previous elements
            for (int j = 0; j < i; j++) {
                // If strictly increasing and adding arr[i] increases the sum
                if (arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
            // Update the answer with the max sum found so far
            overallMax = max(overallMax, dp[i]);
        }
        
        return overallMax;
    }
};