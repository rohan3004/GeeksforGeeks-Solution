#include <vector>
#include <string>

class Solution {
 public:
  std::vector<int> asciirange(std::string& s) {
    // Arrays to store the first and last occurrence index of each character ('a' to 'z').
    std::vector<int> first(26, -1);
    std::vector<int> last(26, -1);
    int n = s.length();

    // First pass: find the first and last occurrences.
    for (int i = 0; i < n; ++i) {
      int char_index = s[i] - 'a';
      if (first[char_index] == -1) {
        first[char_index] = i;
      }
      last[char_index] = i;
    }

    // Second pass: create a prefix sum array for O(1) range sum calculation.
    std::vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      prefix_sum[i + 1] = prefix_sum[i] + static_cast<int>(s[i]);
    }

    std::vector<int> result;

    // Final step: iterate through characters 'a' to 'z' to calculate sums.
    for (int i = 0; i < 26; ++i) {
      // Check if the character appeared and has different first/last positions.
      if (first[i] != -1 && first[i] < last[i]) {
        int start_index = first[i];
        int end_index = last[i];

        // The range to sum is (start_index, end_index).
        // Check if there are any characters between them.
        if (end_index > start_index + 1) {
          // Calculate the sum using the prefix sum array.
          // Sum of s[start_index + 1 ... end_index - 1]
          int current_sum = prefix_sum[end_index] - prefix_sum[start_index + 1];
          result.push_back(current_sum);
        }
      }
    }
    
    return result;
  }
};