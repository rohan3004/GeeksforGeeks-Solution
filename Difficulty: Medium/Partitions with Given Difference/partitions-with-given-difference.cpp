#include <vector>
#include <numeric>

using namespace std;

class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = 0;
        
        for (int num : arr) {
            sum += num;
        }
        
        // If the total sum is less than the difference, or if (sum + diff) is odd,
        // it's mathematically impossible to partition the array as required.
        if (sum < diff || (sum - diff) % 2 != 0) {
            return 0;
        }
        
        // This is the target sum we need to find subsets for
        int target = (sum - diff) / 2;
        
        // dp[j] will store the number of subsets that sum up to j
        vector<int> dp(target + 1, 0);
        
        // Base case: There is 1 way to make a sum of 0 (by choosing an empty subset)
        dp[0] = 1; 
        
        // Populate the DP table
        for (int i = 0; i < n; i++) {
            // Traverse backwards from target down to arr[i] to prevent reusing 
            // the same element in the current iteration.
            for (int j = target; j >= arr[i]; j--) {
                dp[j] = dp[j] + dp[j - arr[i]];
            }
        }
        
        return dp[target];
    }
};