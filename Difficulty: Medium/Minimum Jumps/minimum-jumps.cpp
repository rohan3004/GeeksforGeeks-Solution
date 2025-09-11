#include <vector>
#include <algorithm> // Required for std::max

class Solution {
 public:
  int minJumps(std::vector<int>& arr) {
    int n = arr.size();

    // If there's only one element, we are already at the end.
    if (n <= 1) {
      return 0;
    }

    // If the first element is 0, we can't make the first move.
    if (arr[0] == 0) {
      return -1;
    }

    // The farthest index we can reach so far.
    int max_reach = arr[0];
    
    // The number of steps we have left in the current jump.
    int steps = arr[0];
    
    // The number of jumps we've taken (we start with 1 from index 0).
    int jumps = 1;

    // Iterate from the second element to the end.
    for (int i = 1; i < n; ++i) {
      // If we've reached the last element, return the number of jumps.
      if (i == n - 1) {
        return jumps;
      }

      // Update the farthest reachable index.
      max_reach = std::max(max_reach, i + arr[i]);

      // Use one step to get to the current index.
      steps--;

      // If we have no steps left, we must take another jump.
      if (steps == 0) {
        // Increment the jump counter.
        jumps++;

        // If our current position is stuck and cannot move forward.
        // This means max_reach did not extend beyond our current index.
        if (i >= max_reach) {
          return -1;
        }

        // Update steps to the number of steps in the new jump.
        steps = max_reach - i;
      }
    }

    return -1; // Should not be reached given the constraints and logic.
  }
};