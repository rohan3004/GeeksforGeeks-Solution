#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        
        // dp[j] stores the maximum dot product using a prefix of 'a'
        // and the first 'j' elements of 'b'.
        // Initialize with -1 to represent unreachable states.
        vector<int> dp(m + 1, -1);
        
        // Base case: matching 0 elements from 'b' results in a 0 product
        dp[0] = 0; 
        
        for (int i = 1; i <= n; ++i) {
            // Traverse backwards so we use the dp state from the previous 'i' iteration
            for (int j = min(i, m); j >= 1; --j) {
                // If it's valid to transition from j-1 elements
                if (dp[j - 1] != -1) {
                    dp[j] = max(dp[j], dp[j - 1] + a[i - 1] * b[j - 1]);
                }
            }
        }
        
        return dp[m];
    }
};