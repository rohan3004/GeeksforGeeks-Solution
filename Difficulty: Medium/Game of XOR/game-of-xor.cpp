class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();
        
        // Case 1: If the array length is even, every element appears 
        // in an even number of subarrays. They all cancel out.
        if (n % 2 == 0) {
            return 0;
        }
        
        // Case 2: If the array length is odd, only elements at 
        // even indices (0, 2, 4...) appear an odd number of times.
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            ans ^= arr[i];
        }
        
        return ans;
    }
};