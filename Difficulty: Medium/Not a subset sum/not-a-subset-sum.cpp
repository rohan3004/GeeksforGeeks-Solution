class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // Step 1: Sort the array in ascending order
        sort(arr.begin(), arr.end());
        
        // Step 2: Initialize the smallest impossible sum to 1
        long long res = 1;
        
        // Step 3: Iterate through the array to build contiguous sums
        for (int i = 0; i < arr.size(); i++) {
            // If the current element is greater than the smallest missing sum,
            // we have found our gap. We cannot form 'res'.
            if (arr[i] > res) {
                break;
            }
            
            // Otherwise, we expand our reachable sums by adding the current element.
            // We can now form all sums up to (res + arr[i] - 1).
            res += arr[i];
        }
        
        return res;
    }
};