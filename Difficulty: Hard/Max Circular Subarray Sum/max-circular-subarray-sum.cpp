#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
 public:
  /**
   * @brief Finds the maximum possible sum of a non-empty subarray in a circular array.
   * * @param arr The input vector of integers.
   * @return The maximum circular subarray sum.
   */
  int maxCircularSum(std::vector<int> &arr) {
    int n = arr.size();

    // 1. Calculate the total sum of the array and find the min/max non-wrapping subarray sums in one pass.
    int total_sum = 0;
    
    // Kadane's algorithm for maximum subarray sum (non-wrapping)
    int max_so_far = arr[0];
    int current_max = arr[0];

    // Kadane's algorithm for minimum subarray sum
    int min_so_far = arr[0];
    int current_min = arr[0];
    
    total_sum += arr[0];

    for (int i = 1; i < n; ++i) {
        // Accumulate total sum
        total_sum += arr[i];

        // Process for max subarray sum
        current_max = std::max(arr[i], current_max + arr[i]);
        max_so_far = std::max(max_so_far, current_max);
        
        // Process for min subarray sum
        current_min = std::min(arr[i], current_min + arr[i]);
        min_so_far = std::min(min_so_far, current_min);
    }
    
    // 2. Handle the edge case where all numbers are negative.
    // In this case, min_so_far will be equal to total_sum.
    // The wrapping sum (total_sum - min_so_far) would be 0, which is wrong.
    // The correct answer is the non-wrapping max sum (the largest negative number).
    if (min_so_far == total_sum) {
      return max_so_far;
    }
    
    // 3. Calculate the maximum wrapping subarray sum.
    int max_wrap_sum = total_sum - min_so_far;
    
    // 4. The result is the maximum of the non-wrapping and wrapping sums.
    return std::max(max_so_far, max_wrap_sum);
  }
};