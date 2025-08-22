#include <vector>
#include <algorithm> // Required for std::upper_bound

class Solution {
 public:
  /**
   * @brief Finds the median of a row-wise sorted matrix.
   *
   * This function uses binary search on the range of possible median values [1, 2000].
   * For each potential median 'mid', it counts how many elements in the matrix are
   * less than or equal to 'mid'. This count is done efficiently by using
   * binary search (upper_bound) on each sorted row.
   *
   * Based on the count, the search space for the median value is narrowed down until
   * the correct median is found.
   *
   * Time Complexity: O(n * log(m) * log(max_val)), where max_val is the upper bound of element values (2000).
   * Space Complexity: O(1).
   *
   * @param mat The n x m row-wise sorted matrix with odd dimensions.
   * @return The median of the matrix.
   */
  int median(std::vector<std::vector<int>> &mat) {
    int n = mat.size();
    if (n == 0) return 0;
    int m = mat[0].size();
    if (m == 0) return 0;

    // The desired count of elements that should be less than or equal to the median.
    // For a total of N = n*m elements, the median is the ((N/2) + 1)-th smallest element.
    int median_pos = (n * m) / 2 + 1;

    // Binary search on the possible values of the median, which are constrained to be between 1 and 2000.
    int low = 1;
    int high = 2000;
    int ans = 0;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      int count = 0;

      // For each row, count the number of elements less than or equal to mid.
      for (int i = 0; i < n; ++i) {
        // std::upper_bound returns an iterator to the first element greater than 'mid'.
        // The distance from the beginning of the row to this iterator gives the
        // count of elements that are less than or equal to 'mid'.
        count += std::upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
      }

      // If the count of elements <= mid is less than what's required for a median,
      // then the actual median must be a larger value.
      if (count < median_pos) {
        low = mid + 1;
      } else {
        // If the count is sufficient, 'mid' could be the median. We store it
        // and try to find if an even smaller value also satisfies the condition.
        ans = mid;
        high = mid - 1;
      }
    }
    return ans;
  }
};