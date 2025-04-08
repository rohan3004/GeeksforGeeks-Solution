//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node, vector<bool>& visited, vector<int> adj[]) {
          visited[node] = true;
          for (auto neighbor : adj[node]) {
              if (!visited[neighbor]) {
                  dfs(neighbor, visited, adj);
              }
          }
      }
      
      bool isBridge(int V, vector<vector<int>>& edges, int c, int d) {
          // Create adjacency list
          vector<int> adj[V];
          for (auto edge : edges) {
              adj[edge[0]].push_back(edge[1]);
              adj[edge[1]].push_back(edge[0]);
          }
          
          // Count connected components before removing edge
          vector<bool> visited(V, false);
          int initialComponents = 0;
          for (int i = 0; i < V; i++) {
              if (!visited[i]) {
                  initialComponents++;
                  dfs(i, visited, adj);
              }
          }
          
          // Remove edge (c, d)
          auto it = find(adj[c].begin(), adj[c].end(), d);
          if (it != adj[c].end()) adj[c].erase(it);
          
          it = find(adj[d].begin(), adj[d].end(), c);
          if (it != adj[d].end()) adj[d].erase(it);
          
          // Count connected components after removing edge
          fill(visited.begin(), visited.end(), false);
          int newComponents = 0;
          for (int i = 0; i < V; i++) {
              if (!visited[i]) {
                  newComponents++;
                  dfs(i, visited, adj);
              }
          }
          
          // If components increased, it's a bridge
          return newComponents > initialComponents;
      }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends