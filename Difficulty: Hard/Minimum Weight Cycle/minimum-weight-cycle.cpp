//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
 int findMinCycle(int V, vector<vector<int>>& edges) {
        const int INF = 1000000000; // A large number representing infinity
        int i, j, k;
        
        // Create and initialize matrices.
        // dp[i][j] will eventually represent the shortest path distance from i to j
        // using only vertices < k as intermediate vertices.
        vector<vector<int>> dp(V, vector<int>(V, INF));
        vector<vector<int>> graph(V, vector<int>(V, INF));

        // Every vertex has zero cost to itself.
        for (i = 0; i < V; i++) {
            dp[i][i] = 0;
            graph[i][i] = 0;
        }

        // Fill the matrices with the given edge weights.
        int sizeEdges = edges.size();
        for (i = 0; i < sizeEdges; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            // In case multiple edges exist between two vertices keep the minimum.
            if (w < graph[u][v]) {
                graph[u][v] = w;
                graph[v][u] = w;  // Graph is undirected.
                dp[u][v] = w;
                dp[v][u] = w;
            }
        }

        int result = INF;
        // Perform the modified Floyd–Warshall procedure.
        // Process vertices one by one as potential intermediates.
        for (k = 0; k < V; k++) {
            // Check for cycles that involve vertex k.
            // Here we try every pair (i, j) with i < j < k.
            // The idea is that dp[i][j] is already the shortest distance from i to j using vertices < k.
            // If there are also direct edges between i and k and between j and k, we have a cycle.
            for (i = 0; i < k; i++) {
                for (j = i + 1; j < k; j++) {
                    if (dp[i][j] < INF && graph[i][k] < INF && graph[k][j] < INF) {
                        int cycleWeight = dp[i][j] + graph[i][k] + graph[k][j];
                        if (cycleWeight < result) {
                            result = cycleWeight;
                        }
                    }
                }
            }
            // Update dp using vertex k as an intermediate vertex.
            for (i = 0; i < V; i++) {
                for (j = 0; j < V; j++) {
                    if (dp[i][k] < INF && dp[k][j] < INF && dp[i][j] > dp[i][k] + dp[k][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
        return (result == INF) ? -1 : result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends