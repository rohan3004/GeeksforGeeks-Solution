class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        result.reserve(queries.size()); // Optimization to avoid reallocations
        
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int x = query[2];
            
            // Define the iterators for the specific subarray range [l, r]
            // We use 'r + 1' because standard library ranges are [start, end) (exclusive end)
            auto startIt = arr.begin() + l;
            auto endIt = arr.begin() + r + 1;
            
            // Find the first occurrence of x
            auto lower = std::lower_bound(startIt, endIt, x);
            
            // Find the first element strictly greater than x
            auto upper = std::upper_bound(startIt, endIt, x);
            
            // The count is the number of elements between these two positions
            result.push_back(std::distance(lower, upper));
        }
        
        return result;
    }
};