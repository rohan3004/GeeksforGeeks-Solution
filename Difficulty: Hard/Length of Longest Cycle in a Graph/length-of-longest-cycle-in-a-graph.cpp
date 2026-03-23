class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> next_node(V, -1);
        vector<int> indegree(V, 0);
        
        // 1. Build the graph and calculate in-degrees
        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];
            next_node[u] = v;
            indegree[v]++;
        }
        
        queue<int> q;
        vector<bool> vis(V, false);
        
        // 2. Add all nodes with 0 in-degree to the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // 3. Kahn's Algorithm to trim non-cycle branches
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = true; // Mark as processed/not in a cycle
            
            int v = next_node[u];
            if (v != -1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        int max_cycle = -1;
        
        // 4. Traverse remaining nodes to find cycle lengths
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                int curr = i;
                int current_length = 0;
                
                // Traverse the cycle
                while (!vis[curr]) {
                    vis[curr] = true;
                    curr = next_node[curr];
                    current_length++;
                }
                
                max_cycle = max(max_cycle, current_length);
            }
        }
        
        return max_cycle;
    }
};