#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
 public:
  /**
   * @brief Helper function to check if a character is a lowercase vowel.
   * @param c The character to check.
   * @return True if the character is a vowel, false otherwise.
   */
  inline bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

  /**
   * @brief Counts the number of balanced contiguous string subarrays.
   * @param arr The input array of strings.
   * @return The number of balanced subarrays.
   */
  int countBalanced(std::vector<std::string>& arr) {
    // Use long long for the count to avoid overflow, as the number of
    // subarrays can be large (up to ~N^2/2).
    long long balanced_count = 0;

    // Stores the running prefix sum of (vowels - consonants).
    // The total number of characters is < 10^5, so the sum fits in an int.
    int current_sum = 0;

    // A map to store the frequency of each prefix sum encountered.
    // Key: prefix sum, Value: frequency.
    std::unordered_map<int, int> prefix_sum_counts;

    // Initialize with a prefix sum of 0 having occurred once (the empty prefix).
    // This handles cases where a subarray starting from index 0 is balanced.
    prefix_sum_counts[0] = 1;

    // Iterate through each string in the input array.
    for (const std::string& s : arr) {
      int vowels = 0;
      // Count vowels in the current string.
      for (char c : s) {
        if (isVowel(c)) {
          vowels++;
        }
      }

      // The difference for the current string is (vowels - consonants).
      // This can be simplified: diff = vowels - (s.length() - vowels)
      // which is diff = 2 * vowels - s.length().
      int diff = 2 * vowels - static_cast<int>(s.length());

      // Update the running prefix sum.
      current_sum += diff;

      // If the current_sum has been seen before, it means the subarray(s)
      // between the previous occurrences and the current position have a
      // net difference of 0 (i.e., they are balanced).
      if (prefix_sum_counts.count(current_sum)) {
        balanced_count += prefix_sum_counts[current_sum];
      }

      // Increment the frequency of the current prefix sum in the map.
      prefix_sum_counts[current_sum]++;
    }

    // The function signature requires an int, so we cast the result.
    // This assumes the final count fits within an int for the provided test cases.
    return static_cast<int>(balanced_count);
  }
};