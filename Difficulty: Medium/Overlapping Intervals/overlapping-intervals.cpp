#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Edge case: empty array
        if (arr.empty()) {
            return {};
        }

        // Step 1: Sort intervals by start time
        sort(arr.begin(), arr.end());

        vector<vector<int>> result;
        
        // Push the first interval to start
        result.push_back(arr[0]);

        // Step 2: Iterate through the rest
        for (int i = 1; i < arr.size(); i++) {
            // Get the last interval in the result (the one we are currently merging into)
            // We use a reference to modify it directly
            vector<int>& lastInterval = result.back();
            
            // Get the current interval from the sorted array
            vector<int>& currentInterval = arr[i];

            // Step 3: Check for overlap
            // If current start <= last end
            if (currentInterval[0] <= lastInterval[1]) {
                // Merge: Update the end time to the max of both end times
                lastInterval[1] = max(lastInterval[1], currentInterval[1]);
            } else {
                // No overlap: Push the current interval as a new entry
                result.push_back(currentInterval);
            }
        }

        return result;
    }
};