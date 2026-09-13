class Solution {
public:
    int partyHouse(vector<vector<int>> &adj) {
        int n = adj.size();
        if (n <= 1) return 0;

        // Helper lambda function to perform BFS and find the farthest node & its distance
        auto bfs = [&](int start) -> pair<int, int> {
            vector<int> dist(n, -1);
            queue<int> q;

            q.push(start);
            dist[start] = 0;

            int farthestNode = start;
            int maxDist = 0;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neighbor : adj[curr]) {
                    // Convert 1-based index to 0-based to match vector indices
                    int v = neighbor - 1; 
                    if (dist[v] == -1) {
                        dist[v] = dist[curr] + 1;
                        q.push(v);
                        if (dist[v] > maxDist) {
                            maxDist = dist[v];
                            farthestNode = v;
                        }
                    }
                }
            }
            return {farthestNode, maxDist};
        };

        // Step 1: Find the farthest node from an arbitrary starting point (node 0)
        pair<int, int> p1 = bfs(0);

        // Step 2: Run BFS from the farthest node found to get the tree's true diameter
        pair<int, int> p2 = bfs(p1.first);

        int diameter = p2.second;

        // The minimum possible maximum distance is the radius of the tree
        return (diameter + 1) / 2;
    }
};