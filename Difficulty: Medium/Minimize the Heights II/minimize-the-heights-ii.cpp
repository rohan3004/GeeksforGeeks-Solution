#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int getMinDiff(vector<int> &arr, int k) {
    int n = arr.size();
    // If there's only one tower or no towers, the difference is 0.
    if (n <= 1) {
      return 0;
    }

    // 1. Sort the array to easily manage min/max values.
    sort(arr.begin(), arr.end());

    // 2. Initialize the answer with the initial difference.
    // This is the baseline if we add k to all or subtract k from all.
    int ans = arr[n - 1] - arr[0];

    // 3. Iterate through all possible partition points.
    // A partition at 'i' means we add k to arr[0...i-1] and subtract k from arr[i...n-1].
    for (int i = 1; i < n; ++i) {
      // Check for the validity constraint: heights must be non-negative.
      // Since the array is sorted, we only need to check the smallest element
      // that we are decreasing, which is arr[i].
      if (arr[i] - k < 0) {
        continue;
      }
      
      // Calculate the potential new min and max for this partition.
      // The new minimum is either the smallest tower increased (arr[0] + k)
      // or the first tower of the second part decreased (arr[i] - k).
      int new_min = min(arr[0] + k, arr[i] - k);

      // The new maximum is either the last tower of the first part increased (arr[i-1] + k)
      // or the largest tower decreased (arr[n-1] - k).
      int new_max = max(arr[i - 1] + k, arr[n - 1] - k);
      
      // Update the answer with the smaller difference.
      ans = min(ans, new_max - new_min);
    }
    
    return ans;
  }
};