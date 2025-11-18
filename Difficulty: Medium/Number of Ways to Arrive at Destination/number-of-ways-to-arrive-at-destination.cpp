#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // 1. Create Adjacency List
        // Graph is undirected, so add edges both ways
        vector<pair<int, int>> adj[V];
        for(auto& it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // 2. Initialize Priority Queue, dist array, and ways array
        // Min-heap stores {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist(V, INT_MAX);
        vector<long long> ways(V, 0); // Using long long to prevent potential overflow during addition

        // 3. Set start node conditions
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        // 4. Process the graph
        while(!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Optimization: If current d is greater than what we already found, skip
            if (d > dist[u]) continue;

            for(auto& it : adj[u]) {
                int v = it.first;
                int time = it.second;

                // CASE 1: Found a strictly shorter path
                if(dist[u] + time < dist[v]) {
                    dist[v] = dist[u] + time;
                    ways[v] = ways[u]; // Inherit the number of ways
                    pq.push({dist[v], v});
                }
                // CASE 2: Found another path with the same shortest duration
                else if(dist[u] + time == dist[v]) {
                    ways[v] = (ways[v] + ways[u]); 
                    // Note: In some versions of this problem (like LeetCode 1976), 
                    // you are required to use modulo 10^9 + 7 here.
                }
            }
        }

        // 5. Return the number of shortest ways to reach the last node
        // If destination is unreachable, ways[V-1] will remain 0
        return (int)ways[V - 1];
    }
};