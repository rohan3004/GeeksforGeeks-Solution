#include <vector>
#include <numeric>

using namespace std;

class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }
        
        // Edge cases: if the required sum is odd, or if target is unreachable
        if (totalSum + target < 0 || (totalSum + target) % 2 != 0) {
            return 0;
        }
        
        // The subset sum we need to find
        int reqSum = (totalSum + target) / 2;
        
        // dp[i] will store the number of ways to reach sum 'i'
        vector<int> dp(reqSum + 1, 0);
        
        // There is 1 way to make a sum of 0 (by choosing no elements)
        dp[0] = 1;
        
        for (int num : arr) {
            // Traverse backwards to use values from the previous iteration safely
            for (int j = reqSum; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[reqSum];
    }
};