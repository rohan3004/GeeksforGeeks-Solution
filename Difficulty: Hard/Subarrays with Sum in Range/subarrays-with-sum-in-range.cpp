class Solution {
private:
    // Helper function to count subarrays with sum <= target
    long long countAtMost(const vector<int>& arr, long long target) {
        if (target < 0) return 0;
        
        long long count = 0;
        long long current_sum = 0;
        int left = 0;
        int n = arr.size();
        
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            
            // Shrink the window if the sum exceeds the target
            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }
            
            // Add the number of valid subarrays ending at 'right'
            count += (right - left + 1);
        }
        
        return count;
    }

public:
    int countSubarray(vector<int>& arr, int l, int r) {
        // Number of subarrays in [l, r] is:
        // (subarrays with sum <= r) - (subarrays with sum <= l - 1)
        long long count_r = countAtMost(arr, r);
        long long count_l_minus_1 = countAtMost(arr, l - 1);
        
        return count_r - count_l_minus_1;
    }
};