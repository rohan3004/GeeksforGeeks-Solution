class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int n = arr.size();
        
        // Initialize variables
        int max_normal = arr[0];    // Max sum for non-circular case
        int curr_max = arr[0];      // Current max for Kadane's
        
        int min_normal = arr[0];    // Min sum (to subtract for circular case)
        int curr_min = arr[0];      // Current min for inverse Kadane's
        
        int total_sum = arr[0];
        
        for(int i = 1; i < n; i++) {
            total_sum += arr[i];
            
            // Standard Kadane's for Max Subarray Sum
            curr_max = max(arr[i], curr_max + arr[i]);
            max_normal = max(max_normal, curr_max);
            
            // Inverse Kadane's for Min Subarray Sum
            curr_min = min(arr[i], curr_min + arr[i]);
            min_normal = min(min_normal, curr_min);
        }
        
        // Edge Case: If all numbers are negative, max_normal will be negative.
        // In this case, the maximum sum is just the largest single element (max_normal).
        // (Total - Min) would incorrectly give 0 (empty array logic).
        if(max_normal < 0) {
            return max_normal;
        }
        
        // Return the max of non-circular vs circular cases
        return max(max_normal, total_sum - min_normal);
    }
};