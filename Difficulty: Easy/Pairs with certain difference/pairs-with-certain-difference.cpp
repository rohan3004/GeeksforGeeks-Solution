#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // Sort the array in descending order to prioritize larger elements
        sort(arr.begin(), arr.end(), greater<int>());
        
        int maxSum = 0;
        int n = arr.size();
        
        for (int i = 0; i < n - 1; ) {
            // Check if the difference is strictly less than k
            if (arr[i] - arr[i+1] < k) {
                maxSum += arr[i] + arr[i+1]; // Add to total sum
                i += 2;                      // Skip both elements since they are now paired
            } else {
                i += 1;                      // Skip current element, check the next one
            }
        }
        
        return maxSum;
    }
};