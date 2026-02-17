#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // Basic edge case check (though constraints say size >= 2)
        if (arr.empty()) return 0;
        
        int n = arr.size();
        vector<int> startTimes(n);
        vector<int> endTimes(n);
        
        // 1. Separate start and end times
        for(int i = 0; i < n; i++) {
            startTimes[i] = arr[i][0];
            endTimes[i] = arr[i][1];
        }
        
        // 2. Sort both arrays
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());
        
        int maxOverlap = 0;
        int currentOverlap = 0;
        int i = 0; // pointer for startTimes
        int j = 0; // pointer for endTimes
        
        // 3. Iterate through the intervals
        // We only need to run while there are start times left to process.
        // Once all start times are processed, the overlap count can only decrease.
        while (i < n) {
            // If the next interval starts before (or exactly when) the current smallest end time finishes
            if (startTimes[i] <= endTimes[j]) {
                currentOverlap++;
                maxOverlap = max(maxOverlap, currentOverlap);
                i++;
            } else {
                // An interval has ended
                currentOverlap--;
                j++;
            }
        }
        
        return maxOverlap;
    }
};