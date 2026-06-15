#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int> &cost, int w) {
        int n = cost.size();
        
        // Initialize DP array with a large value representing "infinity"
        // 1e9 is safe here because max possible cost is w * max_cost = 2000 * 10^5 = 2*10^8
        vector<int> dp(w + 1, 1e9);
        
        // Base case: cost to buy 0 kg is 0
        dp[0] = 0;
        
        // Iterate through all weights from 1 to w
        for (int i = 1; i <= w; ++i) {
            // Check all available packets
            for (int j = 0; j < n; ++j) {
                int weight = j + 1; // 0-based index means index j has weight j+1
                
                // If packet is available, fits in current weight, and we can reach the previous state
                if (cost[j] != -1 && i >= weight && dp[i - weight] != 1e9) {
                    dp[i] = min(dp[i], dp[i - weight] + cost[j]);
                }
            }
        }
        
        // If dp[w] is still 1e9, we couldn't find a way to buy exactly w kg
        return dp[w] == 1e9 ? -1 : dp[w];
    }
};