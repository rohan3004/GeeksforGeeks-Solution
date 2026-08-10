#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();
        
        // Edge cases
        if (n == 0) return 0;
        if (n == 1) return max(h[0], l[0]);
        
        // prev2 represents dp[i-2], prev1 represents dp[i-1]
        int prev2 = max(h[0], l[0]);
        int prev1 = max(prev2 + l[1], h[1]);
        
        // Iterate through the remaining days
        for (int i = 2; i < n; ++i) {
            int curr = max(prev1 + l[i], prev2 + h[i]);
            
            // Shift the window forward
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};