#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
 public:
  /**
   * @brief Finds the length of the longest subarray where the count of elements > k is more than the count of elements <= k.
   * * @param arr The input array of integers.
   * @param k The integer value for comparison.
   * @return The length of the longest valid subarray.
   */
  int longestSubarray(std::vector<int> &arr, int k) {
    int n = arr.size();
    if (n == 0) {
        return 0;
    }

    // Step 1: Create a prefix sum array S.
    // S[i] stores the prefix sum of the first 'i' elements of the transformed array.
    // The transformed array has +1 for arr[j] > k and -1 for arr[j] <= k.
    std::vector<int> S(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        S[i + 1] = S[i] + (arr[i] > k ? 1 : -1);
    }

    // The sums in S can range from -n to n. We use an offset to map them to
    // non-negative indices for our helper arrays.
    int offset = n;
    int helper_array_size = 2 * n + 2;

    // Step 2: Populate 'f' array.
    // f[sum + offset] stores the first index 'i' where S[i] == sum.
    // Initialize with a value larger than any possible index (0 to n).
    std::vector<int> f(helper_array_size, n + 1);
    for (int i = 0; i <= n; ++i) {
        int sum = S[i];
        if (f[sum + offset] == n + 1) {
            f[sum + offset] = i;
        }
    }

    // Step 3: Populate 'g' array.
    // g[v + offset] stores the minimum first index for all sums <= v.
    // This is a running minimum of the 'f' array.
    std::vector<int> g(helper_array_size, n + 1);
    g[0] = f[0];
    for (int i = 1; i < helper_array_size; ++i) {
        g[i] = std::min(g[i - 1], f[i]);
    }

    // Step 4: Find the maximum length. We want to maximize j - i where S[j] > S[i].
    // For each j, we need the smallest i such that S[i] < S[j].
    // The smallest index for any sum <= S[j]-1 is given by g[S[j]-1 + offset].
    int maxLength = 0;
    for (int j = 1; j <= n; ++j) {
        int current_sum = S[j];
        int target_sum_val = current_sum - 1;
        int target_sum_idx = target_sum_val + offset;

        // Ensure the index is within the bounds of the 'g' array.
        if (target_sum_idx >= 0 && target_sum_idx < helper_array_size) {
            int i = g[target_sum_idx];
            // If a valid earlier index 'i' is found.
            if (i < j) {
                maxLength = std::max(maxLength, j - i);
            }
        }
    }

    return maxLength;
  }
};