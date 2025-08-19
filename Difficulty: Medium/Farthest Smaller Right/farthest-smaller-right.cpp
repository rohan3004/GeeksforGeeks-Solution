#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> tree;
    // According to constraints, the maximum value in arr is 10^6.
    static const int MAX_VAL = 1000000;

    /**
     * @brief Updates the segment tree with the index of a value.
     * @param node The current node in the segment tree.
     * @param start The start of the value range for this node.
     * @param end The end of the value range for this node.
     * @param val_idx The value from the input array to update.
     * @param arr_idx The index of the value in the input array.
     */
    void update(int node, int start, int end, int val_idx, int arr_idx) {
        if (start == end) {
            tree[node] = max(tree[node], arr_idx);
            return;
        }
        int mid = start + (end - start) / 2;
        if (val_idx <= mid) {
            update(2 * node, start, mid, val_idx, arr_idx);
        } else {
            update(2 * node + 1, mid + 1, end, val_idx, arr_idx);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    /**
     * @brief Queries the segment tree for the maximum index in a given value range.
     * @param node The current node in the segment tree.
     * @param start The start of the value range for this node.
     * @param end The end of the value range for this node.
     * @param l The left boundary of the query's value range.
     * @param r The right boundary of the query's value range.
     * @return The maximum index found in the range [l, r], or -1 if none.
     */
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l || l > r) {
            return -1;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return max(p1, p2);
    }

public:
    /**
     * @brief Finds the farthest index j > i such that arr[j] < arr[i] for each element.
     * @param arr The input array of integers.
     * @return A vector of integers with the results.
     */
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        // The segment tree size is 4 * MAX_VAL to be safe. Initialize with -1.
        tree.assign(4 * (MAX_VAL + 1), -1);
        
        vector<int> ans(n);
        
        // Iterate from right to left
        for (int i = n - 1; i >= 0; --i) {
            int current_val = arr[i];
            
            // Query for the farthest index of a value smaller than current_val.
            // The range of values to check is [1, current_val - 1].
            if (current_val > 1) {
                ans[i] = query(1, 1, MAX_VAL, 1, current_val - 1);
            } else {
                // No value can be smaller than 1 as per constraints.
                ans[i] = -1; 
            }
            
            // Update the segment tree with the current element's information.
            // The value is current_val and its index is i.
            update(1, 1, MAX_VAL, current_val, i);
        }
        
        return ans;
    }
};