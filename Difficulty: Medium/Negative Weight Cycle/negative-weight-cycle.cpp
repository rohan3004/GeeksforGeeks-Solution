class Solution {
public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        // Initialize distances to all vertices as 0.
        // This covers disconnected components seamlessly.
        vector<int> dist(V, 0);

        // Relax all edges V - 1 times
        for (int i = 0; i < V - 1; i++) {
            bool relaxed = false;
            for (const auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    relaxed = true;
                }
            }
            // Optimization: If no distances were updated, we can stop early 
            // as there's definitely no negative cycle.
            if (!relaxed) {
                break;
            }
        }

        // V-th iteration to check for negative-weight cycle
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            // If we can still relax an edge, a negative cycle exists
            if (dist[u] + w < dist[v]) {
                return true;
            }
        }

        return false;
    }
};