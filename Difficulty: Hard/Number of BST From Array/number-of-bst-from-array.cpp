#include <vector>

class Solution {
 public:
  std::vector<int> countBSTs(std::vector<int>& arr) {
    // Precomputed Catalan numbers up to C(5).
    // C(n) is the number of unique BSTs with n nodes.
    // C(0)=1, C(1)=1, C(2)=2, C(3)=5, C(4)=14, C(5)=42.
    std::vector<int> catalan = {1, 1, 2, 5, 14, 42};

    int n = arr.size();
    if (n == 0) {
      return {};
    }

    std::vector<int> result;
    result.reserve(n); // Optional: for minor performance improvement

    // Iterate through each element of arr, considering it as the root.
    for (int i = 0; i < n; ++i) {
      int root_val = arr[i];
      int left_nodes_count = 0;
      int right_nodes_count = 0;

      // Count elements smaller (for the left subtree) and larger (for the right subtree).
      for (int j = 0; j < n; ++j) {
        if (arr[j] < root_val) {
          left_nodes_count++;
        } else if (arr[j] > root_val) {
          right_nodes_count++;
        }
      }

      // The total number of unique BSTs is the product of the number of
      // unique BSTs that can be formed by the left and right subtrees.
      // This is C(left_nodes_count) * C(right_nodes_count).
      long long total_bsts = (long long)catalan[left_nodes_count] * catalan[right_nodes_count];
      result.push_back(total_bsts);
    }

    return result;
  }
};