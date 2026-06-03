#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // Map to store the 0-based indices at which each element occurs
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < arr.size(); ++i) {
            indices[arr[i]].push_back(i);
        }

        vector<int> result;
        result.reserve(queries.size()); // Pre-allocate memory for efficiency

        // Process each query
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int x = q[2];

            // If the element x doesn't exist in our map, its frequency is 0
            if (indices.find(x) == indices.end()) {
                result.push_back(0);
            } else {
                const auto& positions = indices[x];
                
                // Find the first index >= l
                auto left_it = lower_bound(positions.begin(), positions.end(), l);
                
                // Find the first index > r
                auto right_it = upper_bound(positions.begin(), positions.end(), r);
                
                // The number of occurrences in range is the distance between the two iterators
                result.push_back(distance(left_it, right_it));
            }
        }

        return result;
    }
};