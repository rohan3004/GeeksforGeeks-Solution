class Solution {
public:
    int bitonic(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;
        
        // inc[i] stores the length of the increasing subarray ending at index i
        vector<int> inc(n, 1);
        // dec[i] stores the length of the decreasing subarray starting at index i
        vector<int> dec(n, 1);
        
        // Left to right pass to fill inc[]
        for (int i = 1; i < n; i++) {
            // Monotonically increasing means arr[i] >= arr[i-1]
            if (arr[i] >= arr[i - 1]) {
                inc[i] = inc[i - 1] + 1;
            }
        }
        
        // Right to left pass to fill dec[]
        for (int i = n - 2; i >= 0; i--) {
            // Monotonically decreasing means arr[i] >= arr[i+1]
            if (arr[i] >= arr[i + 1]) {
                dec[i] = dec[i + 1] + 1;
            }
        }
        
        // Find the maximum length of a bitonic subarray
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            // -1 because the peak element arr[i] is counted twice (in both inc and dec)
            int current_bitonic_len = inc[i] + dec[i] - 1;
            if (current_bitonic_len > max_len) {
                max_len = current_bitonic_len;
            }
        }
        
        return max_len;
    }
};