#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        if (V <= 1) return {0};

        vector<vector<int>> adj(V);
        vector<int> degree(V, 0);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> leaves;
        for (int i = 0; i < V; i++) {
            if (degree[i] == 1) {
                leaves.push(i); // Fixed
            }
        }

        int remainingNodes = V;
        while (remainingNodes > 2) {
            int leafCount = leaves.size();
            remainingNodes -= leafCount;
            
            for (int i = 0; i < leafCount; i++) {
                int leaf = leaves.front();
                leaves.pop(); // Fixed
                
                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        leaves.push(neighbor); // Fixed
                    }
                }
            }
        }

        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};