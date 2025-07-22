#include <vector>
#include <cmath> // For std::abs

class Solution {
 public:
  /**
   * @brief Finds the smallest positive missing number in an array.
   * @param arr The input vector of integers.
   * @return The smallest positive integer missing from the array.
   */
  int missingNumber(std::vector<int> &arr) {
    int n = arr.size();

    // 1. Segregate non-positives and numbers > n.
    // Replace them with a value (n + 1) that is out of our range of interest [1, n].
    for (int i = 0; i < n; ++i) {
      if (arr[i] <= 0 || arr[i] > n) {
        arr[i] = n + 1;
      }
    }

    // 2. Use the array as a hash map.
    // For each element arr[i], mark the presence of the number `abs(arr[i])`
    // by negating the value at the index `abs(arr[i]) - 1`.
    for (int i = 0; i < n; ++i) {
      int val = std::abs(arr[i]);
      if (val > 0 && val <= n) {
        int index = val - 1;
        // Check if the value at the index is positive before negating
        // to avoid negating it twice.
        if (arr[index] > 0) {
          arr[index] = -arr[index];
        }
      }
    }

    // 3. Find the first positive number.
    // The index of the first positive number `i` corresponds to the missing number `i + 1`.
    for (int i = 0; i < n; ++i) {
      if (arr[i] > 0) {
        return i + 1;
      }
    }

    // 4. If all numbers from 1 to n are present, then n+1 is the missing number.
    return n + 1;
  }
};