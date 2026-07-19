class Solution {
public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        
        // right_up[i] stores the furthest index to the right we can reach 
        // from i while the elements are non-decreasing.
        vector<int> right_up(n);
        right_up[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] <= arr[i + 1]) {
                right_up[i] = right_up[i + 1];
            } else {
                right_up[i] = i;
            }
        }
        
        // left_down[i] stores the furthest index to the left we can reach 
        // from i while the elements are non-increasing.
        vector<int> left_down(n);
        left_down[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i] <= arr[i - 1]) {
                left_down[i] = left_down[i - 1];
            } else {
                left_down[i] = i;
            }
        }
        
        vector<bool> result;
        result.reserve(queries.size());
        
        // Process each query in O(1) time
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            // If the peak achievable from the left meets/crosses 
            // the peak achievable from the right, it's a mountain.
            if (right_up[l] >= left_down[r]) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        
        return result;
    }
};