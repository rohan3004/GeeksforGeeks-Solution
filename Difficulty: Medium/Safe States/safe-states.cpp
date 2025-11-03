#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<int> safeNodes(int V, vector<vector<int>>& edges) {
    // 1. Build reversed graph and calculate original out-degrees
    vector<vector<int>> adjRev(V);
    vector<int> outDegree(V, 0);

    for (const auto& edge : edges) {
      int u = edge[0];
      int v = edge[1];
      // Original edge: u -> v
      // We add a reversed edge: v -> u
      adjRev[v].push_back(u);
      // Increment the out-degree of the source node u
      outDegree[u]++;
    }

    // 2. Initialize queue with all terminal nodes (out-degree == 0)
    queue<int> q;
    for (int i = 0; i < V; ++i) {
      if (outDegree[i] == 0) {
        q.push(i);
      }
    }

    // 3. Process nodes using BFS (Kahn's algorithm)
    vector<int> safeNodesList;
    while (!q.empty()) {
      int node = q.front();
      q.pop();

      // This node is safe
      safeNodesList.push_back(node);

      // 4. Check all nodes that pointed to this 'node' in the original graph
      for (int neighbor : adjRev[node]) {
        // "Remove" the edge from neighbor -> node
        outDegree[neighbor]--;

        // If 'neighbor' now has no other outgoing edges to unsafe nodes,
        // it becomes safe.
        if (outDegree[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }

    // 5. Sort the result in ascending order
    sort(safeNodesList.begin(), safeNodesList.end());

    return safeNodesList;
  }
};