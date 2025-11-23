class Solution {
public:
    // Helper function to perform DFS traversal
    void dfs(int index, vector<int> adj[], vector<bool>& visited) {
        visited[index] = true;
        // Visit all adjacent stones (stones sharing row/col)
        for(int neighbor : adj[index]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        
        // Adjacency list to represent the graph
        // adj[i] contains indices of stones connected to stone i
        vector<int> adj[n];

        // Step 1: Build the graph
        // Iterate through all pairs to find connections
        // Time Complexity for this part: O(N^2)
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                // If stones share a row (x) or column (y)
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Step 2: Count Connected Components
        int componentCount = 0;
        vector<bool> visited(n, false);

        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                // Found a new unvisited component
                componentCount++;
                // Visit all stones in this component
                dfs(i, adj, visited);
            }
        }

        // Step 3: Calculate result
        // Max removable = Total Stones - Number of Components (1 stone kept per component)
        return n - componentCount;
    }
};