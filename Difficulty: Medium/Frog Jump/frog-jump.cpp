#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        
        // If there's 0 or 1 stair, no cost.
        if (n <= 1) {
            return 0;
        }

        // Initialize variables to store the costs for the base cases.
        // prev2 stores the cost to reach stair i-2 (starts at dp[0])
        int prev2 = 0; 
        
        // prev1 stores the cost to reach stair i-1 (starts at dp[1])
        int prev1 = abs(height[1] - height[0]);

        // Iterate from the 3rd stair (index 2) up to the last stair
        for (int i = 2; i < n; ++i) {
            
            // Cost if jumping from stair i-1
            int cost_one_step = prev1 + abs(height[i] - height[i - 1]);
            
            // Cost if jumping from stair i-2
            int cost_two_steps = prev2 + abs(height[i] - height[i - 2]);
            
            // The minimum cost to reach stair i
            int current = min(cost_one_step, cost_two_steps);
            
            // Update the previous values for the next iteration
            // The old prev1 becomes the new prev2
            prev2 = prev1;
            // The new current cost becomes the new prev1
            prev1 = current;
        }
        
        // After the loop, prev1 holds the minimum cost to reach the last stair (n-1)
        return prev1;
    }
};