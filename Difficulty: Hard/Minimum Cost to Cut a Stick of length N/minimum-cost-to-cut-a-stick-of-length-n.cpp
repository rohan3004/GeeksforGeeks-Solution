#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        // 1. Create a new array including the stick boundaries (0 and n)
        vector<int> new_cuts;
        new_cuts.push_back(0); // Add the start of the stick
        for (int c : cuts) {
            new_cuts.push_back(c);
        }
        new_cuts.push_back(n); // Add the end of the stick
        
        // 2. Sort the cuts. This is crucial for the interval DP.
        sort(new_cuts.begin(), new_cuts.end());

        int m = new_cuts.size();

        // 3. Initialize the DP table
        // dp[i][j] = minimum cost to make all cuts in the
        //            interval [new_cuts[i], new_cuts[j]]
        // We initialize with 0, as the base cases (len < 2) are 0.
        vector<vector<int>> dp(m, vector<int>(m, 0));

        // 4. Iterate using the "gap" or "length" of the interval
        // 'len' represents the distance between i and j
        // We start at len = 2 (e.g., [0, 2, 4]) because len = 1 (e.g., [0, 2])
        // is our base case with a cost of 0.
        for (int len = 2; len < m; len++) {
            // 'i' is the starting index of the segment
            for (int i = 0; i <= m - 1 - len; i++) {
                // 'j' is the ending index of the segment
                int j = i + len;

                // The cost of the *first* cut on this segment [i, j]
                // is always the length of the segment.
                int segment_cost = new_cuts[j] - new_cuts[i];
                
                // Initialize the cost for this dp state as max
                dp[i][j] = INT_MAX;

                // 'k' is the "split point". We try every possible 'k'
                // between i and j to find the minimum cost.
                for (int k = i + 1; k < j; k++) {
                    
                    // Total cost = (cost of this cut) + 
                    //              (min cost of left sub-problem) + 
                    //              (min cost of right sub-problem)
                    int total_cost = segment_cost + dp[i][k] + dp[k][j];
                    
                    dp[i][j] = min(dp[i][j], total_cost);
                }
            }
        }

        // 5. The final answer is the min cost for the original segment [0, n],
        // which corresponds to dp[0][m-1] in our new_cuts array.
        return dp[0][m - 1];
    }
};