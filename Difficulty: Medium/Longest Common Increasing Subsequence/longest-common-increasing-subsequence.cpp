#include <vector>
#include <algorithm> // For std::max and std::max_element

using namespace std;

class Solution {
 public:
  /**
   * Finds the length of the Longest Common Increasing Subsequence (LCIS).
   *
   * @param a The first array.
   * @param b The second array.
   * @return The length of the LCIS.
   */
  int LCIS(vector<int> &a, vector<int> &b) {
    int n = a.size();
    int m = b.size();

    if (n == 0 || m == 0) {
      return 0;
    }

    // dp[j] will store the length of the LCIS ending at b[j]
    // considering elements from a[0...i]
    vector<int> dp(m, 0);

    // Iterate through each element of array 'a'
    for (int i = 0; i < n; i++) {
      // 'current_length' stores the max length of an LCIS ending at some b[k]
      // (where k < j) such that b[k] < a[i].
      int current_length = 0;

      // Iterate through each element of array 'b'
      for (int j = 0; j < m; j++) {
        
        // Case 1: Elements match
        if (a[i] == b[j]) {
          // The new length for dp[j] can be 1 (for a[i]) + current_length
          // (the longest LCIS ending before b[j] with a value < a[i]).
          // We take the max in case a previous element from 'a'
          // already created a longer LCIS ending at b[j].
          dp[j] = max(dp[j], 1 + current_length);
        }

        // Case 2: b[j] is a potential predecessor
        if (b[j] < a[i]) {
          // If b[j] is smaller than a[i], it could be the element
          // just before a[i] in a future LCIS.
          // We update current_length to the max LCIS ending at
          // such a b[j] seen so far.
          current_length = max(current_length, dp[j]);
        }
      }
    }

    // The result is the maximum value in the dp array,
    // as the LCIS could end at any element of 'b'.
    int max_lcis = 0;
    for (int len : dp) {
      max_lcis = max(max_lcis, len);
    }

    return max_lcis;
  }
};