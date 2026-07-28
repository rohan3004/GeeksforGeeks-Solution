#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>>& edges) {
        // We will transform the graph to have only weight-1 edges.
        // The maximum number of dummy nodes we might need is equal to the number of edges.
        int num_edges = edges.size();
        
        // Adjacency list expanded to accommodate the original V nodes + dummy nodes
        vector<vector<int>> adj(V + num_edges);
        
        // nxt_node starts at V and increments every time we need a dummy node
        int nxt_node = V; 
        
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            
            if (w == 1) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            } else if (w == 2) {
                // Split the weight 2 edge using a dummy intermediate node
                adj[u].push_back(nxt_node);
                adj[nxt_node].push_back(u);
                
                adj[nxt_node].push_back(v);
                adj[v].push_back(nxt_node);
                
                nxt_node++; // Increment for the next possible dummy node
            }
        }
        
        // Perform standard BFS on the unweighted graph
        vector<int> dist(nxt_node, -1);
        queue<int> q;
        
        q.push(src);
        dist[src] = 0;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            // If we reach the destination, return the recorded distance
            if (curr == dest) {
                return dist[curr];
            }
            
            for (int neighbor : adj[curr]) {
                if (dist[neighbor] == -1) { // If the node is unvisited
                    dist[neighbor] = dist[curr] + 1;
                    q.push(neighbor);
                }
            }
        }
        
        // Return -1 if destination is entirely unreachable from src
        return -1; 
    }
};