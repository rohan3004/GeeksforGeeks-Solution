class Solution {
private:
    // Helper function for DSU: Find the representative (root) of the set containing i
    int find(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        // Path compression
        return parent[i] = find(parent, parent[i]);
    }

    // Helper function for DSU: Union of sets containing u and v
    // Returns true if a union (merge) occurred, false if already in the same set
    bool unite(vector<int>& parent, int u, int v) {
        int rootU = find(parent, u);
        int rootV = find(parent, v);

        if (rootU != rootV) {
            // Union by rank/size could be used, but for simplicity,
            // we'll just set one parent to the other.
            parent[rootU] = rootV;
            return true; // A new connection was made, components merged
        }
        return false; // Already connected, this is an extra link
    }

public:
    int minConnect(int V, vector<vector<int>>& edges) {
        // Edge case: A fully connected graph requires at least V-1 edges.
        // If E < V - 1, it's impossible, even if all edges are extra.
        if (edges.size() < V - 1) {
            return -1;
        }

        // 1. Initialize DSU
        vector<int> parent(V);
        for (int i = 0; i < V; ++i) {
            parent[i] = i;
        }

        int components = V;  // Initially, V components
        int extraLinks = 0;  // Count of redundant edges

        // 2. Process Edges
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (unite(parent, u, v)) {
                // If a merge happened, decrease the component count
                components--;
            } else {
                // If already connected, this edge is redundant and can be reused
                extraLinks++;
            }
        }

        // 3. Check Condition
        // If components == 1, all are connected, return 0. (components - 1 = 0)
        // If components > 1, we need (components - 1) operations.
        int requiredOperations = components - 1;

        // We need 'requiredOperations' links to connect the 'components' groups.
        // We have 'extraLinks' available to be moved.
        if (extraLinks >= requiredOperations) {
            return requiredOperations;
        } else {
            // Not enough extra links to bridge the components
            return -1;
        }
    }
};