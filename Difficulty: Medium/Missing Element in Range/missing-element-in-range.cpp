#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // Step 1: Insert all array elements into a hash set for O(1) lookups
        unordered_set<int> elements(arr.begin(), arr.end());
        
        vector<int> result;
        
        // Step 2: Iterate through the given range [low, high]
        for (int i = low; i <= high; i++) {
            
            // Step 3: If the current number 'i' is NOT in the set, it is missing
            if (elements.find(i) == elements.end()) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};