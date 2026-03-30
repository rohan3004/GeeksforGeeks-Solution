#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        
        // Track the minimum distance to include each house into the MST
        vector<int> minDist(n, INT_MAX);
        // Track which houses are already part of the MST
        vector<bool> inMST(n, false);
        
        // Start from the first house (index 0)
        minDist[0] = 0;
        int totalCost = 0;
        
        for (int i = 0; i < n; ++i) {
            // Step 1: Find the unvisited house with the minimum distance
            int u = -1;
            for (int j = 0; j < n; ++j) {
                if (!inMST[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }
            
            // Step 2: Include this house in the MST
            inMST[u] = true;
            totalCost += minDist[u];
            
            // Step 3: Update the minimum distances for the remaining unvisited houses
            for (int v = 0; v < n; ++v) {
                if (!inMST[v]) {
                    // Calculate Manhattan distance between house u and house v
                    int dist = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    
                    // Update the minimum distance if a cheaper connection is found
                    if (dist < minDist[v]) {
                        minDist[v] = dist;
                    }
                }
            }
        }
        
        return totalCost;
    }
};