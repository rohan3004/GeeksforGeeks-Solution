#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        
        // 1. Build the adjacency list from the edge list.
        vector<vector<int>> adj(V);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Initialize min_cycle to a value larger than any possible cycle (V+1 or just infinity)
        int min_cycle = 1e9 + 7;

        // 2. Iterate through each edge (u, v) in the graph
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // 3. Find the shortest path from u to v, *excluding* the direct edge (u, v)
            queue<int> q;
            q.push(u);
            
            // dist[i] will store the shortest distance from u to i
            vector<int> dist(V, -1);
            dist[u] = 0;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                // Optimization: If we've already found a path and the current
                // distance is larger, we can't find a shorter cycle here.
                // This isn't strictly necessary but can be a small optimization.
                // We'll skip it for clarity, but the main `break` is below.

                // When we find the target vertex 'v', we've found the shortest path
                if (curr == v) {
                    break;
                }

                for (int neighbor : adj[curr]) {
                    // 4. This is the "temporary remove" part.
                    // We skip the direct edge (u, v)
                    if ((curr == u && neighbor == v) || (curr == v && neighbor == u)) {
                        continue;
                    }

                    // Standard BFS: if not visited, update dist and add to queue
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[curr] + 1;
                        q.push(neighbor);
                    }
                }
            }

            // 5. If we found the end vertex 'v' (dist[v] != -1),
            // it means we found a path, and thus a cycle.
            if (dist[v] != -1) {
                // The cycle length is the path length (dist[v]) + 1 (for the removed edge)
                min_cycle = min(min_cycle, dist[v] + 1);
            }
        }

        // 6. If min_cycle was never updated, no cycles exist.
        if (min_cycle == 1e9 + 7) {
            return -1;
        } else {
            return min_cycle;
        }
    }
};