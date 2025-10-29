#include <vector>
#include <unordered_map>
#include <utility> // For std::pair
#include <algorithm> // For std::max

using namespace std;

class Solution {
private:
    // This helper function performs a DFS to find the farthest node from 'startNode'.
    // - u: The current node
    // - p: The parent node (to avoid going backward)
    // - currentDist: The distance from the DFS start to node 'u'
    // - farthestNodeInfo: A reference to a pair {node, distance} to store the result.
    // - adj: The adjacency list of the graph.
    void findFarthestNode(int u, int p, int currentDist, 
                          pair<int, int>& farthestNodeInfo, 
                          unordered_map<int, vector<int>>& adj) {
        
        // If this node 'u' is farther than the one we've seen so far, update it.
        if (currentDist > farthestNodeInfo.second) {
            farthestNodeInfo = {u, currentDist};
        }

        // Continue the DFS for all neighbors.
        for (int v : adj[u]) {
            // We only move to a neighbor 'v' if it's not the parent 'p'.
            if (v != p) {
                findFarthestNode(v, u, currentDist + 1, farthestNodeInfo, adj);
            }
        }
    }

public:
    int diameter(int V, vector<vector<int>>& edges) {
        // 1. Build the adjacency list from the edge list.
        // An unordered_map is used, but a vector<vector<int>>(V) would also work.
        unordered_map<int, vector<int>> adj;
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // --- First Pass ---
        // 2. Find the farthest node from an arbitrary starting point (e.g., node 0).
        // 'farthest_1' will store {node_id, distance}
        pair<int, int> farthest_1 = {0, 0}; // {node, distance}
        // Start DFS from node 0, with no parent (-1), and distance 0.
        findFarthestNode(0, -1, 0, farthest_1, adj);

        // --- Second Pass ---
        // 3. Find the farthest node from the node we just found (farthest_1.first).
        // 'farthest_2' will store the endpoint of the diameter and the diameter itself.
        pair<int, int> farthest_2 = {farthest_1.first, 0};
        // Start DFS from the farthest node, with no parent (-1), and distance 0.
        findFarthestNode(farthest_1.first, -1, 0, farthest_2, adj);

        // 4. The distance found in the second pass is the diameter of the tree.
        return farthest_2.second;
    }
};