#include <vector>

class Solution {
public:
    bool divisibleByK(std::vector<int>& arr, int k) {
        int n = arr.size();
        
        // Pigeonhole Principle: If n >= k, there's always a subarray 
        // (which is a valid subset) whose sum is divisible by k.
        if (n >= k) return true;
        
        // dp[i] will be true if a subset sum with remainder i modulo k exists
        std::vector<bool> dp(k, false);
        
        for (int i = 0; i < n; i++) {
            // Use a temporary array to avoid using the same element multiple times
            std::vector<bool> temp = dp;
            int val = arr[i] % k;
            
            // The element itself forms a valid subset
            temp[val] = true;
            
            // Add the current element to all previously found subset sums
            for (int j = 0; j < k; j++) {
                if (dp[j]) {
                    temp[(j + val) % k] = true;
                }
            }
            
            dp = temp;
            
            // If we found a subset sum perfectly divisible by k, return true
            if (dp[0]) return true;
        }
        
        return false;
    }
};