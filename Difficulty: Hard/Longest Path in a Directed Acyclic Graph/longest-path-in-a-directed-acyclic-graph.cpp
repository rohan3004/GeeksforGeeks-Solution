#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // Step 1: Build the adjacency list and compute in-degrees for Kahn's Algorithm
        vector<vector<pair<int, int>>> adj(V);
        vector<int> inDegree(V, 0);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            inDegree[v]++;
        }

        // Step 2: Perform Topological Sort using Kahn's Algorithm (BFS)
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        topo.reserve(V);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Step 3: Calculate the longest paths
        vector<int> dist(V, INT_MIN);
        dist[src] = 0;

        // Process vertices strictly in topological order
        for (int u : topo) {
            // If the current vertex is reachable from the source
            if (dist[u] != INT_MIN) {
                for (const auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    
                    // Relax the edge to maximize the distance
                    if (dist[u] + weight > dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        return dist;
    }
};