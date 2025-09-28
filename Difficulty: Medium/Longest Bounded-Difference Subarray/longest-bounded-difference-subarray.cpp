#include <vector>
#include <deque>
#include <algorithm>

class Solution {
 public:
  /**
   * @brief Finds the longest subarray where the absolute difference between any two elements is not greater than x.
   * * This solution utilizes a sliding window approach, defined by pointers 'start' and 'end'.
   * To efficiently find the minimum and maximum elements within the current window arr[start...end],
   * we use two deques (double-ended queues):
   * 1. min_dq: Stores indices of elements from the current window, with the corresponding values
   * in increasing order. The front of the deque always points to the minimum element.
   * 2. max_dq: Stores indices of elements from the current window, with the corresponding values
   * in decreasing order. The front of the deque always points to the maximum element.
   * * The algorithm iterates through the array with the 'end' pointer, expanding the window.
   * For each new element, we update the deques. If the condition (max - min <= x) is violated,
   * we shrink the window from the left by incrementing the 'start' pointer and removing any
   * out-of-bounds indices from the deques.
   * * This approach ensures that each element is processed a constant number of times, leading to
   * an optimal time complexity of O(n).
   * * @param arr The input vector of positive integers.
   * @param x The maximum allowed absolute difference.
   * @return The longest valid subarray. If multiple exist, the one with the smallest starting index is returned.
   */
  std::vector<int> longestSubarray(std::vector<int>& arr, int x) {
    int n = arr.size();
    if (n == 0) {
      return {};
    }

    std::deque<int> min_dq;
    std::deque<int> max_dq;
    
    int start = 0;
    int maxLength = 0;
    int result_start_index = 0;

    for (int end = 0; end < n; ++end) {
      // Maintain min_dq: remove elements from the back that are greater than the current element.
      while (!min_dq.empty() && arr[min_dq.back()] >= arr[end]) {
        min_dq.pop_back();
      }
      min_dq.push_back(end);

      // Maintain max_dq: remove elements from the back that are smaller than the current element.
      while (!max_dq.empty() && arr[max_dq.back()] <= arr[end]) {
        max_dq.pop_back();
      }
      max_dq.push_back(end);

      // Shrink the window from the left if the condition is violated.
      // The condition is: max_element - min_element <= x
      while (arr[max_dq.front()] - arr[min_dq.front()] > x) {
        // If the element at 'start' is the current min or max, its index needs to be removed.
        if (min_dq.front() == start) {
          min_dq.pop_front();
        }
        if (max_dq.front() == start) {
          max_dq.pop_front();
        }
        // Shrink the window by moving the start pointer.
        start++;
      }

      // Update the result if the current window is the longest found so far.
      int currentLength = end - start + 1;
      if (currentLength > maxLength) {
        maxLength = currentLength;
        result_start_index = start;
      }
    }
    
    // Construct the result vector from the start index and length of the longest valid subarray.
    return std::vector<int>(arr.begin() + result_start_index, arr.begin() + result_start_index + maxLength);
  }
};