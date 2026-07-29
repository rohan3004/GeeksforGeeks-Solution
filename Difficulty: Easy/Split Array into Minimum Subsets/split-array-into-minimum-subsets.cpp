class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        if (arr.empty()) return 0;
        
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        // We will always have at least 1 subset if the array is not empty
        int count = 1;
        
        // Step 2: Traverse and count gaps
        for (int i = 1; i < arr.size(); i++) {
            // If the current element is not strictly one more than the previous,
            // it starts a new consecutive subset.
            if (arr[i] != arr[i - 1] + 1) {
                count++;
            }
        }
        
        return count;
    }
};