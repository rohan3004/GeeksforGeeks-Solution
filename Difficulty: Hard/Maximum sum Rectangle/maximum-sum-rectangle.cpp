#include <vector>
#include <algorithm>
#include <climits>

class Solution {
 public:
  /**
   * @brief Finds the maximum sum of a submatrix within the given 2D matrix.
   * * @param mat The input 2D matrix of integers.
   * @return The maximum possible sum of any submatrix.
   */
  int maxRectSum(std::vector<std::vector<int>> &mat) {
    if (mat.empty() || mat[0].empty()) {
        return 0;
    }

    int n = mat.size();    // Number of rows
    int m = mat[0].size(); // Number of columns
    int max_global_sum = INT_MIN;

    // Iterate through all possible left column boundaries
    for (int left = 0; left < m; ++left) {
        // This vector will store the sum of elements for each row
        // from the 'left' column to the current 'right' column.
        std::vector<int> row_sums(n, 0);

        // Iterate through all possible right column boundaries
        for (int right = left; right < m; ++right) {
            
            // Update the row_sums array with the elements from the current 'right' column
            for (int i = 0; i < n; ++i) {
                row_sums[i] += mat[i][right];
            }

            // Apply Kadane's algorithm on the 'row_sums' array.
            // This finds the maximum sum subarray, which corresponds to the
            // optimal top and bottom rows for the fixed left and right columns.
            int current_max_sum = row_sums[0];
            int max_ending_here = row_sums[0];

            for (int i = 1; i < n; ++i) {
                max_ending_here = std::max(row_sums[i], max_ending_here + row_sums[i]);
                current_max_sum = std::max(current_max_sum, max_ending_here);
            }

            // Update the overall maximum sum found so far.
            max_global_sum = std::max(max_global_sum, current_max_sum);
        }
    }

    return max_global_sum;
  }
};