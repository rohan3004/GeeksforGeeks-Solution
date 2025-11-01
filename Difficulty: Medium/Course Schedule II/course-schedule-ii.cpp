#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        // 1. Build the graph (adjacency list) and in-degree array
        vector<vector<int>> adj(n);
        vector<int> in_degree(n, 0);
        
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            // Edge from prerequisite -> course
            adj[prereq].push_back(course);
            // Increment in-degree of the course that has a prerequisite
            in_degree[course]++;
        }

        // 2. Initialize the queue with all courses having 0 in-degree
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo_order;
        
        // 3. Process the queue
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            topo_order.push_back(u);

            // Iterate over neighbors of u
            for (int v : adj[u]) {
                // "Remove" the edge from u to v by decrementing in-degree
                in_degree[v]--;
                
                // If v now has no prerequisites, add it to the queue
                if (in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // 4. Check for cycles
        if (topo_order.size() == n) {
            return topo_order; // Valid order found
        } else {
            return {}; // Cycle detected, impossible to finish
        }
    }
};