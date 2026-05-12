#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    // Helper function to calculate GCD
    long long get_gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    // Helper function to calculate LCM safely
    long long get_lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / get_gcd(a, b)) * b;
    }

    // Build the segment tree
    void buildTree(int node, int start, int end, const vector<int>& arr, vector<long long>& tree) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(2 * node + 1, start, mid, arr, tree);
        buildTree(2 * node + 2, mid + 1, end, arr, tree);
        
        tree[node] = get_lcm(tree[2 * node + 1], tree[2 * node + 2]);
    }

    // Update a point in the segment tree
    void updateTree(int node, int start, int end, int idx, int val, vector<long long>& tree) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (start <= idx && idx <= mid) {
            updateTree(2 * node + 1, start, mid, idx, val, tree);
        } else {
            updateTree(2 * node + 2, mid + 1, end, idx, val, tree);
        }
        
        tree[node] = get_lcm(tree[2 * node + 1], tree[2 * node + 2]);
    }

    // Query the LCM of a range
    long long queryTree(int node, int start, int end, int L, int R, const vector<long long>& tree) {
        // Completely outside the given range
        if (R < start || L > end) {
            return 1; // 1 is the identity value for LCM
        }
        // Completely inside the given range
        if (L <= start && end <= R) {
            return tree[node];
        }
        
        // Partially inside and partially outside
        int mid = start + (end - start) / 2;
        long long left_lcm = queryTree(2 * node + 1, start, mid, L, R, tree);
        long long right_lcm = queryTree(2 * node + 2, mid + 1, end, L, R, tree);
        
        return get_lcm(left_lcm, right_lcm);
    }

public:
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        
        // Segment tree array (size 4 * n is sufficient)
        vector<long long> tree(4 * n);
        
        // Build the tree initially
        buildTree(0, 0, n - 1, arr, tree);
        
        vector<long long> result;
        
        // Process the queries
        for (const auto& q : queries) {
            if (q[0] == 1) {
                // Update Query: [1, index, value]
                updateTree(0, 0, n - 1, q[1], q[2], tree);
            } else if (q[0] == 2) {
                // Range Query: [2, L, R]
                result.push_back(queryTree(0, 0, n - 1, q[1], q[2], tree));
            }
        }
        
        return result;
    }
};