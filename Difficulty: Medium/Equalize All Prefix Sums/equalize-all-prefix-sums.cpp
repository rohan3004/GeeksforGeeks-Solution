#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        int n = arr.size();
        
        // The resultant array initialized to 0. 
        // For i = 0, the operations are trivially 0.
        vector<int> ans(n, 0);
        
        // Build the answer using the previously computed prefix state
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + arr[i] - arr[i / 2];
        }
        
        return ans;
    }
};