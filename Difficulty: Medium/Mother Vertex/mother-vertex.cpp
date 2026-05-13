#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void dfs(int u, const vector<vector<int>>& adj, vector<bool>& vis, int& last_v) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj, vis, last_v);
            }
        }
        // Update the last finished vertex
        last_v = u;
    }

    void dfsCount(int u, const vector<vector<int>>& adj, vector<bool>& vis, int& count) {
        vis[u] = true;
        count++;
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfsCount(v, adj, vis, count);
            }
        }
    }

    void dfsRev(int u, const vector<vector<int>>& rev_adj, vector<bool>& vis, int& min_v) {
        vis[u] = true;
        // Keep track of the smallest vertex index found in the SCC
        min_v = min(min_v, u);
        for (int v : rev_adj[u]) {
            if (!vis[v]) {
                dfsRev(v, rev_adj, vis, min_v);
            }
        }
    }

public:
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        // Step 2: Find the last finished vertex in DFS
        vector<bool> vis(V, false);
        int last_v = -1;
        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                dfs(i, adj, vis, last_v);
            }
        }

        // Step 3: Verify if the last finished vertex is actually a mother vertex
        fill(vis.begin(), vis.end(), false);
        int count = 0;
        dfsCount(last_v, adj, vis, count);

        // If it cannot reach all vertices, no mother vertex exists
        if (count != V) {
            return -1;
        }

        // Step 4: Build the reversed graph to find all other mother vertices in the same SCC
        vector<vector<int>> rev_adj(V);
        for (const auto& edge : edges) {
            rev_adj[edge[1]].push_back(edge[0]);
        }

        // Step 5: Traverse reversed graph from the known mother vertex to find the minimum index
        fill(vis.begin(), vis.end(), false);
        int min_v = last_v;
        dfsRev(last_v, rev_adj, vis, min_v);

        return min_v;
    }
};