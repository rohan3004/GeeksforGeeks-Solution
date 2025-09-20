#include <vector>
#include <numeric>   // For std::iota
#include <algorithm> // For std::max, std::swap

// Disjoint Set Union (DSU) or Union-Find data structure.
// Used to keep track of connected components of indices.
struct DSU {
    std::vector<int> parent;
    std::vector<int> sz; // size of each component

    // Constructor initializes n elements, each in its own set.
    DSU(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0); // Fills with 0, 1, 2, ...
        sz.assign(n, 1);
    }

    // Finds the representative (root) of the set containing element i.
    // Uses path compression for optimization.
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    // Merges the sets containing elements i and j.
    // Uses union by size for optimization.
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            // Ensure root_i corresponds to the larger set
            if (sz[root_i] < sz[root_j])
                std::swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
        }
    }
};

class Solution {
 public:
  int longestSubarray(std::vector<int>& arr) {
    int n = arr.size();
    if (n == 0) {
      return 0;
    }

    // Group indices by their value. We only care about values up to n,
    // since the length of any subarray cannot exceed n.
    std::vector<std::vector<int>> val_to_indices(n + 1);
    for (int i = 0; i < n; ++i) {
      if (arr[i] <= n) {
        val_to_indices[arr[i]].push_back(i);
      }
    }

    DSU dsu(n);
    std::vector<bool> active(n, false);
    int max_run = 0; 
    int ans = 0;

    // Iterate through all possible lengths L from 1 to n.
    for (int L = 1; L <= n; ++L) {
      // Activate all indices where the array value is exactly L.
      for (int idx : val_to_indices[L]) {
        active[idx] = true;

        // Check if adjacent indices are already active and merge components.
        // Merge with the left neighbor if it's active.
        if (idx > 0 && active[idx - 1]) {
          dsu.unite(idx, idx - 1);
        }
        // Merge with the right neighbor if it's active.
        if (idx < n - 1 && active[idx + 1]) {
          dsu.unite(idx, idx + 1);
        }
        
        // The length of the current contiguous block is the size of the
        // component that idx now belongs to. Update our tracker for the
        // longest such block seen so far.
        max_run = std::max(max_run, dsu.sz[dsu.find(idx)]);
      }

      // After processing all values equal to L, max_run holds f(L), which is the
      // length of the longest subarray where all elements are less than or equal to L.
      // We are looking for the maximum L where f(L) >= L.
      if (max_run >= L) {
        ans = L; // L is a possible answer, update our best result.
      }
    }

    return ans;
  }
};