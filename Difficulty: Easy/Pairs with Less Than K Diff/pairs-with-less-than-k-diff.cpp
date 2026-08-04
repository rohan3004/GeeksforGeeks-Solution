class Solution {
public:
    int countPairs(vector<int>& arr, int k) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int count = 0;
        int i = 0; // Left pointer
        
        // Step 2: Iterate with the right pointer
        for (int j = 1; j < n; ++j) {
            // Shrink the window from the left if the difference is too large
            while (i < j && arr[j] - arr[i] >= k) {
                i++;
            }
            
            // Add the number of valid pairs that can be formed with arr[j]
            count += (j - i);
        }
        
        return count;
    }
};