#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform, vector<int> &cost) {
        // Use a large value for Infinity, but safe enough to add two of them without overflow
        const int INF = 1e9;
        
        // Adjacency matrix for 26 lowercase letters initialized to INF
        vector<vector<int>> dist(26, vector<int>(26, INF));

        // Distance to self is always 0
        for (int i = 0; i < 26; ++i) {
            dist[i][i] = 0;
        }

        // Fill the graph with initial transformation costs
        for (size_t i = 0; i < transform.size(); ++i) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            int w = cost[i];
            // If there are multiple rules for the same pair, keep the minimum cost
            dist[u][v] = min(dist[u][v], w);
        }

        // Floyd-Warshall Algorithm: Compute All-Pairs Shortest Path
        // This updates dist[i][j] to be the shortest path using any intermediate nodes
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;
        int n = s.size();

        // Iterate through every character position in the strings
        for (int i = 0; i < n; ++i) {
            // If characters match, no cost needed
            if (s[i] == t[i]) continue;

            int charS = s[i] - 'a';
            int charT = t[i] - 'a';
            int minOpCost = INF;

            // Try to transform BOTH chars to a common target character 'target'
            // We check all 26 letters as potential meeting points
            for (int target = 0; target < 26; ++target) {
                if (dist[charS][target] != INF && dist[charT][target] != INF) {
                    int currentOption = dist[charS][target] + dist[charT][target];
                    minOpCost = min(minOpCost, currentOption);
                }
            }

            // If minOpCost is still INF, it means there is no common character reachable
            if (minOpCost == INF) return -1;
            
            totalCost += minOpCost;
        }

        return (int)totalCost;
    }
};