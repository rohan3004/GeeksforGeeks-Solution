#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // Step 1: Insert all array elements into a hash set for O(1) lookups
        unordered_set<int> presentElements(arr.begin(), arr.end());
        
        // Step 2: Iterate through the required range [start, end]
        for (int i = start; i <= end; ++i) {
            // If the current number 'i' is not found in the set, return false
            if (presentElements.find(i) == presentElements.end()) {
                return false;
            }
        }
        
        // Step 3: If all numbers in the range were found, return true
        return true;
    }
};