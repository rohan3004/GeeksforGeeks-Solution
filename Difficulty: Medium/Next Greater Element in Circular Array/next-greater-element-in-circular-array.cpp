#include <vector>
#include <stack>

class Solution {
 public:
  /**
   * @brief Finds the next greater element for each element in a circular array.
   * * @param arr The input circular integer array.
   * @return A vector containing the next greater element for each position.
   */
  std::vector<int> nextGreater(std::vector<int> &arr) {
    int n = arr.size();
    if (n == 0) {
      return {};
    }

    std::vector<int> nge(n, -1);
    std::stack<int> s; // Stack to store indices

    // Iterate twice over the array length to handle circularity.
    // The modulo operator (%) simulates a doubled array arr + arr.
    for (int i = 2 * n - 1; i >= 0; --i) {
      int currentIndex = i % n;

      // Maintain a monotonically decreasing stack.
      // Pop elements that are not greater than the current element.
      while (!s.empty() && arr[s.top()] <= arr[currentIndex]) {
        s.pop();
      }

      // If the stack is not empty, the top element's index points
      // to the next greater element.
      if (!s.empty()) {
        nge[currentIndex] = arr[s.top()];
      }
      
      // Push the current index onto the stack for future comparisons.
      s.push(currentIndex);
    }

    return nge;
  }
};