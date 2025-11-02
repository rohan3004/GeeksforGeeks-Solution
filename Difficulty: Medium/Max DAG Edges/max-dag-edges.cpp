#include <vector>

using namespace std;

class Solution {
  public:
    /**
     * Finds the maximum number of additional edges that can be added to a DAG
     * without forming any cycles, resulting in a "saturated" DAG.
     *
     * @param V The number of vertices in the graph.
     * @param edges A list of existing directed edges, where edges[i] = [u, v].
     * @return The maximum number of edges that can be added.
     */
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // The maximum number of edges a DAG with V vertices can have is
        // equivalent to a complete graph where all edges point in one
        // direction according to a topological sort.
        // This is the total number of ways to choose 2 vertices, V C 2.
        // We use 'long long' to prevent potential overflow during multiplication,
        // although for V <= 1000, it fits within a 32-bit signed int.
        long long max_possible_edges = (long long)V * (V - 1) / 2;
        
        // The number of edges we already have is the size of the input list.
        int current_edges = edges.size();
        
        // The number of edges we can add is the difference between the
        // maximum possible and what we currently have.
        return (int)(max_possible_edges - current_edges);
    }
};