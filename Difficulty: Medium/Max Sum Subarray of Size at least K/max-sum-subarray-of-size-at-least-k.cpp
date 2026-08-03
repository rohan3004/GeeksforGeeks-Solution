class Solution {
public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();
        
        // Sum of the current window of size k
        int window_sum = 0;
        for (int i = 0; i < k; ++i) {
            window_sum += arr[i];
        }
        
        int max_sum = window_sum;
        
        // Variables to keep track of prefix sums
        int prev_prefix_sum = 0;
        int min_prefix_sum = 0;
        
        // Slide the window from index k to n - 1
        for (int i = k; i < n; ++i) {
            // Update the sum of the sliding window of size k
            window_sum += arr[i] - arr[i - k];
            
            // Update the prefix sum prior to the current window
            prev_prefix_sum += arr[i - k];
            
            // Keep track of the minimum prefix sum encountered so far (up to i - k)
            min_prefix_sum = min(min_prefix_sum, prev_prefix_sum);
            
            // The total prefix sum up to index i is (window_sum + prev_prefix_sum)
            // Subtracting the min_prefix_sum gives the max subarray sum ending at i of length >= k
            max_sum = max(max_sum, window_sum + prev_prefix_sum - min_prefix_sum);
        }
        
        return max_sum;
    }
};