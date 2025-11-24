#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
    // Disjoint Set Union (DSU) structure to manage connected components
    struct DSU {
        vector<int> parent;
        
        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
        }
        
        int find(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }
        
        void unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                parent[root_i] = root_j;
            }
        }
    };

public:
    int secondMST(int V, vector<vector<int>>& edges) {
        // 1. Sort edges by weight
        // We add the original index to keep track of edges, 
        // though strictly not needed if we just use the sorted index.
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        // 2. Find the First Best MST
        DSU dsu1(V);
        int minWeight = 0;
        vector<int> mstEdgeIndices; // Stores indices of edges used in the Best MST
        int edgesCount = 0;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (dsu1.find(u) != dsu1.find(v)) {
                dsu1.unite(u, v);
                minWeight += w;
                mstEdgeIndices.push_back(i); // Store the index of this edge
                edgesCount++;
            }
        }

        // If original graph is not connected, no MST exists
        if (edgesCount < V - 1) return -1;

        // 3. Find the Second Best MST by excluding one edge from the Best MST at a time
        int secondBestWeight = -1;

        for (int excludedIndex : mstEdgeIndices) {
            DSU dsu2(V);
            int currentWeight = 0;
            int currentEdgesCount = 0;

            // Re-run Kruskal's, but skip the 'excludedIndex'
            for (int i = 0; i < edges.size(); i++) {
                if (i == excludedIndex) continue; 

                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];

                if (dsu2.find(u) != dsu2.find(v)) {
                    dsu2.unite(u, v);
                    currentWeight += w;
                    currentEdgesCount++;
                }
            }

            // Check if we formed a valid Spanning Tree
            if (currentEdgesCount == V - 1) {
                // Strict check: must be greater than minWeight
                if (currentWeight > minWeight) {
                    if (secondBestWeight == -1 || currentWeight < secondBestWeight) {
                        secondBestWeight = currentWeight;
                    }
                }
            }
        }

        return secondBestWeight;
    }
};