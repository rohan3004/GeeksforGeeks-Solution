//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int findParent(int node, vector<int>& parent) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node], parent); // Path compression
    }

    void unionNodes(int u, int v, vector<int>& parent, vector<int>& rank) {
        int parentU = findParent(u, parent);
        int parentV = findParent(v, parent);

        if (parentU != parentV) {
            if (rank[parentU] > rank[parentV]) {
                parent[parentV] = parentU;
            } else if (rank[parentU] < rank[parentV]) {
                parent[parentU] = parentV;
            } else {
                parent[parentV] = parentU;
                rank[parentU]++;
            }
        }
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> parent(V);
        vector<int> rank(V, 0);

        // Initialize parent array
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int parentU = findParent(u, parent);
            int parentV = findParent(v, parent);

            // If both vertices have the same parent, a cycle is detected
            if (parentU == parentV) return true;

            // Union the two vertices
            unionNodes(u, v, parent, rank);
        }

        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
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