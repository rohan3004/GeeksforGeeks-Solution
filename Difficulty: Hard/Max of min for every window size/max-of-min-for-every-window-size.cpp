#include <vector>
#include <stack>
#include <algorithm>

class Solution {
 public:
  /**
   * @brief Finds the maximum of minimums for every window size.
   * * @param arr The input integer array.
   * @return A vector where the element at index i is the max of mins for window size i+1.
   */
  std::vector<int> maxOfMins(std::vector<int>& arr) {
    int n = arr.size();

    // left[i] stores the index of the first element to the left of arr[i]
    // which is smaller than arr[i].
    std::vector<int> left(n);
    // right[i] stores the index of the first element to the right of arr[i]
    // which is smaller than arr[i].
    std::vector<int> right(n);
    
    std::stack<int> s;

    // Step 1: Calculate Previous Smaller Element (PSE) for all elements.
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && arr[s.top()] >= arr[i]) {
        s.pop();
      }
      left[i] = s.empty() ? -1 : s.top();
      s.push(i);
    }

    // Clear the stack for reuse.
    while (!s.empty()) {
      s.pop();
    }

    // Step 1: Calculate Next Smaller Element (NSE) for all elements.
    for (int i = n - 1; i >= 0; --i) {
      while (!s.empty() && arr[s.top()] >= arr[i]) {
        s.pop();
      }
      right[i] = s.empty() ? n : s.top();
      s.push(i);
    }
    
    // Step 2: Populate initial answers.
    // ans[k] will hold the maximum element that is a minimum in a window of size exactly k.
    // We use 1-based indexing for window size for simplicity.
    std::vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      int len = right[i] - left[i] - 1;
      ans[len] = std::max(ans[len], arr[i]);
    }
    
    // Step 3: Derive final answers.
    // The answer for window size k must be at least the answer for k+1.
    // We fill the ans array from right to left to ensure this property.
    for (int i = n - 1; i >= 1; --i) {
      ans[i] = std::max(ans[i], ans[i + 1]);
    }
    
    // The result should be a 0-indexed vector of size n.
    // We remove the unused ans[0] to align our 1-indexed ans array to the required format.
    ans.erase(ans.begin());
    return ans;
  }
};