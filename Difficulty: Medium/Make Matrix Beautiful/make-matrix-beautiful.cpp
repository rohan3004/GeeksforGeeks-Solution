#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
  /**
   * @brief Calculates the minimum number of operations to make a matrix beautiful.
   * * A beautiful matrix is a square matrix where the sum of elements in every row and
   * every column is equal. An operation consists of incrementing a single cell by 1.
   * * @param mat The input square matrix.
   * @return The minimum number of operations required.
   */
  int balanceSums(std::vector<std::vector<int>>& mat) {
    int n = mat.size();
    if (n == 0) {
      return 0;
    }

    // Use long long for sums to prevent potential integer overflow, as the sums
    // can become large given the problem constraints (N up to 900, values up to 10^6).
    std::vector<long long> rowSum(n, 0);
    std::vector<long long> colSum(n, 0);

    // Step 1: Calculate the sum of each row and each column.
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        rowSum[i] += mat[i][j];
        colSum[j] += mat[i][j];
      }
    }

    // Step 2: Determine the target sum for the beautiful matrix.
    // Since we can only increment values, the final sum of any row or column
    // must be at least its initial sum. To make all sums equal with the minimum
    // number of operations, we must raise all sums to the maximum of all
    // current row and column sums.
    long long maxSum = 0;
    for (int i = 0; i < n; ++i) {
        maxSum = std::max(maxSum, rowSum[i]);
        maxSum = std::max(maxSum, colSum[i]);
    }

    // Step 3: Calculate the total number of operations.
    // The total operations is the sum of increments needed for each row to reach
    // the target sum (maxSum). This is equivalent to the total value that needs
    // to be added to the entire matrix.
    long long operations = 0;
    for (int i = 0; i < n; ++i) {
      operations += (maxSum - rowSum[i]);
    }
    
    // The problem statement asks for an int return type. Based on the constraints,
    // the total number of operations can exceed the maximum value of a 32-bit integer.
    // This implementation assumes the test cases will yield a result that fits
    // within an int, or the environment uses a 64-bit int.
    return static_cast<int>(operations);
  }
};
