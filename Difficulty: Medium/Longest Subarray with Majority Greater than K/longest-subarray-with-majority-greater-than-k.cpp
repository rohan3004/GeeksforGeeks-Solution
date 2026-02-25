class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        
        // We need an offset of (n + 1) so that the minimum possible queried 
        // value of (sum - 1), which is -(n + 1), maps safely to index 0.
        // The maximum sum is +n, which maps to 2n + 1. 
        // Therefore, we need an array of size 2n + 2.
        int offset = n + 1;
        vector<int> first_occ(2 * n + 2, -2);
        
        // Base case: A sum of 0 occurs at conceptual index -1 
        first_occ[0 + offset] = -1; 
        
        int sum = 0;
        int max_len = 0;
        
        for (int i = 0; i < n; ++i) {
            sum += (arr[i] > k) ? 1 : -1;
            
            if (sum > 0) {
                // If sum is positive, the whole array up to index i is valid.
                max_len = i + 1;
            } else {
                // If sum <= 0, we look for the earliest occurrence of (sum - 1).
                if (first_occ[sum - 1 + offset] != -2) {
                    max_len = max(max_len, i - first_occ[sum - 1 + offset]);
                }
            }
            
            // Record the first time we see the current sum
            if (first_occ[sum + offset] == -2) {
                first_occ[sum + offset] = i;
            }
        }
        
        return max_len;
    }
};