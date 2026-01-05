class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Edge case: if k is larger than the array size (though constraints say k <= n)
        if (k > n) return -1; 

        // Use long long for sum variables to prevent integer overflow
        // Max possible sum could be 10^6 * 10^6 = 10^12, which exceeds standard int limit.
        long long currentSum = 0;

        // Step 1: Calculate sum of the first window of size k
        for (int i = 0; i < k; i++) {
            currentSum += arr[i];
        }

        // Initialize maxSum with the sum of the first window
        long long maxSum = currentSum;

        // Step 2: Slide the window from the k-th element to the end
        for (int i = k; i < n; i++) {
            // Add element entering the window (arr[i])
            // Subtract element leaving the window (arr[i - k])
            currentSum += arr[i] - arr[i - k];
            
            // Update maximum sum found so far
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }

        // Cast back to int as per function signature
        return (int)maxSum;
    }
};