#include <vector>

using namespace std;

class Solution {
private:
    // Helper function to find the root parent of a node with Path Compression
    int findParent(int node, vector<int>& parent) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node], parent);
    }
    
    // Helper function to union two components by Rank
    void unionNodes(int u, int v, vector<int>& parent, vector<int>& rank, int& components) {
        int rootU = findParent(u, parent);
        int rootV = findParent(v, parent);
        
        // If they are in different sets, merge them
        if (rootU != rootV) {
            components--; // Merging reduces total isolated components by 1
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootV] < rank[rootU]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
    
public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // If we have fewer edges than (n - 1), it's impossible to connect the graph
        if (edges.size() < n - 1) {
            return -1;
        }
        
        vector<int> parent(n);
        vector<int> rank(n, 0);
        
        // Initially, every node is its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        int components = n;
        
        // Build the graph using Union-Find
        for (const auto& edge : edges) {
            unionNodes(edge[0], edge[1], parent, rank, components);
        }
        
        // We need (components - 1) edges to connect all remaining components
        return components - 1;
    }
};