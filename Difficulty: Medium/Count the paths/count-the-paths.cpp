class Solution {
  public:
    // We store -1 in dp[u] if “number of paths from u → dest” is not yet computed.
    // Otherwise, dp[u] holds the exact count (as a long long) of distinct paths from u to dest.
    vector<long long> dp;
    vector<vector<int>> adj;
    int dest;

    long long dfs(int u) {
        // Base case: if we’ve reached dest, there is exactly 1 path (the “empty” remainder)
        if (u == dest) return 1;

        // If already computed, just return it
        if (dp[u] != -1) return dp[u];

        long long cnt = 0;
        for (int nxt : adj[u]) {
            cnt += dfs(nxt);
        }
        return dp[u] = cnt;
    }

    int countPaths(vector<vector<int>>& edges, int V, int src, int dest_) {
        dest = dest_;
        adj.assign(V, {});
        dp.assign(V, -1);

        // Build adjacency list in O(V + E)
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
        }

        // Launch a memoized DFS from src
        long long answer = dfs(src);

        // The function signature asks for int, so we cast.
        // (All test cases are guaranteed to fit in the target limits.)
        return (int) answer;
    }
};
