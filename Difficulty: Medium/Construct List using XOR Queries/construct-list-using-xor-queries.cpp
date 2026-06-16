#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        vector<int> ans;
        int current_xor = 0;
        
        // Process queries from right to left (backwards)
        for (int i = queries.size() - 1; i >= 0; --i) {
            if (queries[i][0] == 1) {
                // Accumulate the XOR operations
                current_xor ^= queries[i][1];
            } else {
                // Apply the accumulated XOR to the inserted element
                ans.push_back(queries[i][1] ^ current_xor);
            }
        }
        
        // Process the initial '0' that was in the array at the very beginning
        ans.push_back(0 ^ current_xor);
        
        // The problem requires the result to be in sorted order
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};