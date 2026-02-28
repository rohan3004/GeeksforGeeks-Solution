class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int n = arr1.size();
        int m = arr2.size();
        
        int left = 0;             // Start of arr1
        int right = m - 1;        // End of arr2
        
        int diff = INT_MAX;
        vector<int> res(2);
        
        while (left < n && right >= 0) {
            int current_sum = arr1[left] + arr2[right];
            
            // Check if this pair is closer than the previous best
            if (abs(current_sum - x) < diff) {
                diff = abs(current_sum - x);
                res = {arr1[left], arr2[right]};
            }
            
            // Move pointers based on the sum
            if (current_sum > x) {
                right--;
            } else if (current_sum < x) {
                left++;
            } else {
                // Exact match found
                return {arr1[left], arr2[right]};
            }
        }
        
        return res;
    }
};