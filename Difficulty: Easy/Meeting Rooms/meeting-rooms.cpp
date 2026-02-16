#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        // If there are 0 or 1 meetings, attendance is always possible.
        if (arr.empty()) return true;

        // Step 1: Sort the meetings by start time.
        // The default comparison for vector<int> sorts by the first element, then the second.
        sort(arr.begin(), arr.end());

        // Step 2: Iterate through the sorted meetings.
        for (int i = 0; i < arr.size() - 1; i++) {
            
            // Check if the current meeting ends after the next meeting starts.
            // Note: arr[i][1] is current End Time
            //       arr[i+1][0] is next Start Time
            if (arr[i][1] > arr[i + 1][0]) {
                return false;
            }
        }

        return true;
    }
};