#include <vector>
#include <algorithm>

class Solution {
 public:
  /**
   * @brief Finds all elements in an array that appear more than floor(n/3) times.
   * * @param arr The input vector of integers.
   * @return A sorted vector of integers containing the majority elements.
   */
  std::vector<int> findMajority(std::vector<int>& arr) {
    int n = arr.size();
    if (n == 0) {
      return {};
    }

    // Step 1: Find two potential candidates using the Extended Boyer-Moore Voting Algorithm.
    int candidate1 = 0, count1 = 0;
    int candidate2 = 0, count2 = 0;

    for (int num : arr) {
      if (num == candidate1) {
        count1++;
      } else if (num == candidate2) {
        count2++;
      } else if (count1 == 0) {
        candidate1 = num;
        count1 = 1;
      } else if (count2 == 0) {
        candidate2 = num;
        count2 = 1;
      } else {
        // Decrement both counts if the element is different from both candidates.
        count1--;
        count2--;
      }
    }

    // Step 2: Verify the candidates by counting their actual occurrences.
    std::vector<int> result;
    count1 = 0;
    count2 = 0;
    int threshold = n / 3;

    for (int num : arr) {
      if (num == candidate1) {
        count1++;
      } else if (num == candidate2) {
        count2++;
      }
    }

    // Check if the first candidate is a majority element.
    if (count1 > threshold) {
      result.push_back(candidate1);
    }
    
    // Check if the second candidate is a distinct majority element.
    if (candidate1 != candidate2 && count2 > threshold) {
      result.push_back(candidate2);
    }
    
    // As required, sort the final result.
    std::sort(result.begin(), result.end());

    return result;
  }
};