class Solution {
public:
    int maxDiffSubArrays(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return 0;
        
        // Arrays to store the maximum and minimum subarray sums from left and right
        vector<int> leftMax(n), leftMin(n), rightMax(n), rightMin(n);
        
        // 1. Calculate leftMax and leftMin using Kadane's Algorithm
        int curMax = arr[0], curMin = arr[0];
        leftMax[0] = arr[0];
        leftMin[0] = arr[0];
        
        for (int i = 1; i < n; ++i) {
            curMax = max(arr[i], curMax + arr[i]);
            leftMax[i] = max(leftMax[i-1], curMax);
            
            curMin = min(arr[i], curMin + arr[i]);
            leftMin[i] = min(leftMin[i-1], curMin);
        }
        
        // 2. Calculate rightMax and rightMin using Kadane's Algorithm backwards
        curMax = arr[n-1];
        curMin = arr[n-1];
        rightMax[n-1] = arr[n-1];
        rightMin[n-1] = arr[n-1];
        
        for (int i = n - 2; i >= 0; --i) {
            curMax = max(arr[i], curMax + arr[i]);
            rightMax[i] = max(rightMax[i+1], curMax);
            
            curMin = min(arr[i], curMin + arr[i]);
            rightMin[i] = min(rightMin[i+1], curMin);
        }
        
        // 3. Find the maximum absolute difference by trying all split points
        int maxDiff = 0;
        for (int i = 0; i < n - 1; ++i) {
            int diff1 = abs(leftMax[i] - rightMin[i+1]);
            int diff2 = abs(leftMin[i] - rightMax[i+1]);
            maxDiff = max({maxDiff, diff1, diff2});
        }
        
        return maxDiff;
    }
};