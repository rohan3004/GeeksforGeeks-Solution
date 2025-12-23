#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // Step 1: Sort the array to enable binary search.
        // Note: This modifies the original array. If preserving the original 
        // order is required, sort a copy of the array instead.
        sort(arr.begin(), arr.end());
        
        vector<int> result;
        // Reserve memory to avoid reallocations during push_back
        result.reserve(queries.size());
        
        // Step 2: Process each query
        for (const auto& query : queries) {
            int lowerRange = query[0];
            int upperRange = query[1];
            
            // lower_bound returns iterator to the first element >= lowerRange
            auto itLow = lower_bound(arr.begin(), arr.end(), lowerRange);
            
            // upper_bound returns iterator to the first element > upperRange
            auto itHigh = upper_bound(arr.begin(), arr.end(), upperRange);
            
            // The number of elements in range is the distance between iterators
            int count = itHigh - itLow;
            
            result.push_back(count);
        }
        
        return result;
    }
};