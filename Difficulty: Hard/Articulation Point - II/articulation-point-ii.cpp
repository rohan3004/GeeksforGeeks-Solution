class Solution {
private:
    int timer = 0;
    
    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, 
             vector<int>& mark, vector<vector<int>>& adj) {
        
        vis[node] = 1;
        tin[node] = low[node] = ++timer;
        int children = 0;
        
        for (auto it : adj[node]) {
            if (it == parent) continue;
            
            if (!vis[it]) {
                children++;
                dfs(it, node, vis, tin, low, mark, adj);
                
                // Update low of the current node after the DFS call
                low[node] = min(low[node], low[it]);
                
                // Condition for articulation point
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
            } else {
                // Back-edge found
                low[node] = min(low[node], tin[it]);
            }
        }
        
        // Root node condition for articulation point
        if (parent == -1 && children > 1) {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Step 1: Create the adjacency list
        vector<vector<int>> adj(V);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Step 2: Initialize required arrays
        vector<int> vis(V, 0);
        vector<int> tin(V, 0); // Time of insertion/discovery
        vector<int> low(V, 0); // Lowest reachable time
        vector<int> mark(V, 0); // To store unique articulation points
        
        // Step 3: Run DFS for all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        
        // Step 4: Collect results
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }
        
        // Step 5: Handle edge case where no articulation point is found
        if (ans.empty()) {
            return {-1};
        }
        
        return ans;
    }
};