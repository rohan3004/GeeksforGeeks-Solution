class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        
        int arrSum = 0;
        int currVal = 0;
        
        // Calculate initial sum and value
        for (int i = 0; i < n; i++) {
            arrSum += arr[i];
            currVal += i * arr[i];
        }
        
        int maxVal = currVal;
        
        // Compute subsequent values using the rotation formula
        for (int i = 1; i < n; i++) {
            currVal = currVal + arrSum - n * arr[n - i];
            maxVal = max(maxVal, currVal);
        }
        
        return maxVal;
    }
};
