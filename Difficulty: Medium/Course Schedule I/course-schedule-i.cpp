class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        
        // Build the adjacency list and calculate in-degrees
        // Note: [x, y] means y -> x (y is prerequisite for x)
        for (auto& edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }
        
        queue<int> q;
        // Start with courses that have no prerequisites
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        int completedCourses = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            completedCourses++;
            
            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If we processed all nodes, no cycle exists
        return completedCourses == n;
    }
};