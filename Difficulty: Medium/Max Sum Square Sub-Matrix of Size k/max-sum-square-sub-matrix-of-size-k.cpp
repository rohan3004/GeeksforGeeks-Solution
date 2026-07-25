#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        
        // 2D prefix sum array initialized to 0
        // Size is (n + 1) x (n + 1) to handle 1-based indexing easily
        vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
        
        // Step 1: Build the 2D prefix sum array
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = mat[i - 1][j - 1] 
                           + pref[i - 1][j] 
                           + pref[i][j - 1] 
                           - pref[i - 1][j - 1];
            }
        }
        
        int maxSum = INT_MIN;
        
        // Step 2: Iterate through all valid bottom-right corners of k x k grids
        for (int i = k; i <= n; i++) {
            for (int j = k; j <= n; j++) {
                // Calculate the sum of the current k x k sub-grid in O(1) time
                int currentSum = pref[i][j] 
                               - pref[i - k][j] 
                               - pref[i][j - k] 
                               + pref[i - k][j - k];
                
                maxSum = max(maxSum, currentSum);
            }
        }
        
        return maxSum;
    }
};