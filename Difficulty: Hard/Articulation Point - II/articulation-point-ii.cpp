//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
          // Convert edge list to adjacency list
          vector<vector<int>> adj(V);
          for (auto &edge : edges) {
              adj[edge[0]].push_back(edge[1]);
              adj[edge[1]].push_back(edge[0]);
          }
  
          vector<int> disc(V, -1), low(V, -1), parent(V, -1);
          vector<bool> visited(V, false);
          vector<bool> isArticulation(V, false);
          vector<int> result;
  
          function<void(int, int&)> dfs = [&](int u, int &time) {
              visited[u] = true;
              disc[u] = low[u] = ++time;
              int children = 0;
  
              for (int v : adj[u]) {
                  if (!visited[v]) {
                      children++;
                      parent[v] = u;
                      dfs(v, time);
  
                      // Check if the subtree rooted at v has a connection to one of the ancestors of u
                      low[u] = min(low[u], low[v]);
  
                      // Articulation point conditions
                      if ((parent[u] == -1 && children > 1) ||  // Root with more than one child
                          (parent[u] != -1 && low[v] >= disc[u])) {  // Low value of v >= discovery time of u
                          isArticulation[u] = true;
                      }
                  } else if (v != parent[u]) { // Update low value for back edge
                      low[u] = min(low[u], disc[v]);
                  }
              }
          };
  
          int time = 0;
          for (int i = 0; i < V; i++) {
              if (!visited[i]) {
                  dfs(i, time);
              }
          }
  
          for (int i = 0; i < V; i++) {
              if (isArticulation[i]) {
                  result.push_back(i);
              }
          }
  
          return result.empty() ? vector<int>{-1} : result;
      }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends