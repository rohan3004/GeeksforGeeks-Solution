//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
         // Initialize adjacency list and in-degree array
          vector<int> adj[V];
          vector<int> inDegree(V, 0);
  
          // Build the graph
          for (auto& edge : edges) {
              adj[edge[0]].push_back(edge[1]);
              inDegree[edge[1]]++;
          }
  
          // Queue to hold nodes with in-degree 0
          queue<int> q;
  
          // Add all nodes with in-degree 0 to the queue
          for (int i = 0; i < V; i++) {
              if (inDegree[i] == 0) {
                  q.push(i);
              }
          }
  
          // Perform BFS and generate topological ordering
          vector<int> topoOrder;
          while (!q.empty()) {
              int node = q.front();
              q.pop();
              topoOrder.push_back(node);
  
              // Reduce in-degree of adjacent nodes
              for (int neighbor : adj[node]) {
                  inDegree[neighbor]--;
                  if (inDegree[neighbor] == 0) {
                      q.push(neighbor);
                  }
              }
          }
  
          // Check if we have included all nodes in the topological ordering
          if (topoOrder.size() != V) {
              return {}; // Return an empty vector in case of a cycle
          }
  
          return topoOrder;
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        int x = V;
        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(x, res, adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends