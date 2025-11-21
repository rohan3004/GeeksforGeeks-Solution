#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        // Adjacency list: node -> {neighbor, straight_weight, curved_weight}
        // We use a vector of vectors of tuples/arrays for better performance than objects
        vector<vector<vector<int>>> adj(V);
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w1 = edge[2];
            int w2 = edge[3];
            // Undirected graph, add both ways
            adj[u].push_back({v, w1, w2});
            adj[v].push_back({u, w1, w2});
        }

        // dist[i][0] -> shortest path to node i with 0 curved edges used
        // dist[i][1] -> shortest path to node i with 1 curved edge used
        vector<vector<int>> dist(V, vector<int>(2, INT_MAX));

        // Min-heap priority queue storing: {current_cost, current_node, state}
        // state 0 = no curved edge used yet
        // state 1 = curved edge already used
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // Start at source 'a' with 0 cost and state 0
        dist[a][0] = 0;
        dist[a][1] = 0; // Conceptually, cost to reach 'a' with 'a' curved edge is not strictly reachable, 
                        // but we initialize dist[a][0] mainly. 
                        // To be safe/strict, only push state 0.
        pq.push({0, a, 0});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int d = top[0];
            int u = top[1];
            int state = top[2];

            // Optimization: If current d is greater than what we already found, skip
            if (d > dist[u][state]) continue;

            for (const auto& neighbor : adj[u]) {
                int v = neighbor[0];
                int w1 = neighbor[1]; // straight weight
                int w2 = neighbor[2]; // curved weight

                // 1. Try taking the Straight edge (w1)
                // State remains the same (0->0 or 1->1)
                if (dist[u][state] + w1 < dist[v][state]) {
                    dist[v][state] = dist[u][state] + w1;
                    pq.push({dist[v][state], v, state});
                }

                // 2. Try taking the Curved edge (w2)
                // Only allowed if we are currently in state 0 (haven't used one yet)
                // This transitions us to state 1
                if (state == 0) {
                    if (dist[u][0] + w2 < dist[v][1]) {
                        dist[v][1] = dist[u][0] + w2;
                        pq.push({dist[v][1], v, 1});
                    }
                }
            }
        }

        // Answer is the min of reaching b with 0 curved edges or 1 curved edge
        int ans = min(dist[b][0], dist[b][1]);

        return (ans == INT_MAX) ? -1 : ans;
    }
};