#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        
        // Step 1: Build the prefix sum array
        // We can use standard 'int' because the max possible sum is 10^5 * 10^3 = 10^8,
        // which easily fits within the 32-bit signed integer limit (~2.14 * 10^9).
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        vector<int> result;
        result.reserve(queries.size()); // Reserve memory to avoid reallocation overhead

        // Step 2: Process each query in O(1) time
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            // Calculate sum of range [l, r]
            int sum = prefix[r];
            if (l > 0) {
                sum -= prefix[l - 1];
            }
            
            // Calculate count and mean
            int count = r - l + 1;
            
            // Integer division automatically handles the floor for positive numbers
            result.push_back(sum / count); 
        }

        return result;
    }
};