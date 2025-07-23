class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        long long total_sum = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            // Calculate the number of subarrays containing arr[i].
            // (i + 1) is the number of possible start points.
            // (n - i) is the number of possible end points.
            long long occurrences = (long long)(i + 1) * (n - i);
            
            // Add the contribution of the current element to the total sum.
            total_sum += arr[i] * occurrences;
        }
        
        // The problem guarantees the final sum fits in a 32-bit integer.
        return (int)total_sum;
    }
};