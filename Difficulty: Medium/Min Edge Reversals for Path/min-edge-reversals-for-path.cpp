#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        // Create an adjacency list where each node points to a pair of {neighbor, weight}
        vector<vector<pair<int, int>>> adj(n + 1);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, 0}); // Original direction costs 0 reversals
            adj[v].push_back({u, 1}); // Reversed direction costs 1 reversal
        }

        // Distance array initialized to infinity (1e9)
        vector<int> dist(n + 1, 1e9);
        deque<int> dq;

        // Start from the source node
        dq.push_back(src);
        dist[src] = 0;

        while (!dq.empty()) {
            int curr = dq.front();
            dq.pop_front();

            // Explore all neighbors
            for (auto& neighbor : adj[curr]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;

                // If a shorter path is found
                if (dist[curr] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[curr] + weight;

                    // 0-weight edges go to the front, 1-weight edges go to the back
                    if (weight == 0) {
                        dq.push_front(nextNode);
                    } else {
                        dq.push_back(nextNode);
                    }
                }
            }
        }

        // If the destination is unreachable, return -1. Otherwise, return the shortest distance.
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};