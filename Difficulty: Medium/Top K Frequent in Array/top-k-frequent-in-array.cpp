#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
 public:
  /**
   * @brief Finds the top k most frequent elements in an array.
   * * @param arr The input vector of integers.
   * @param k The number of top frequent elements to return.
   * @return A vector containing the top k frequent elements.
   */
  std::vector<int> topKFreq(std::vector<int> &arr, int k) {
    // Step 1: Count the frequency of each element in the array.
    // We use an unordered_map for efficient key-value storage (element -> frequency).
    std::unordered_map<int, int> freqMap;
    for (int num : arr) {
      freqMap[num]++;
    }

    // Step 2: Use a max-heap (priority_queue in C++) to store pairs of {frequency, number}.
    // By default, a priority_queue of pairs sorts by the first element, and if they are
    // equal, it sorts by the second element. This perfectly handles the problem's
    // requirement: sort by frequency, then by the number itself for tie-breaking.
    std::priority_queue<std::pair<int, int>> maxHeap;

    // Populate the max-heap with data from the frequency map.
    for (auto const& [num, freq] : freqMap) {
      maxHeap.push({freq, num});
    }

    // Step 3: Extract the top k elements from the max-heap.
    // The heap's top will always be the element with the highest priority
    // (highest frequency, or largest number in case of a tie).
    std::vector<int> result;
    for (int i = 0; i < k; ++i) {
      // Add the number (the second element of the pair) to our result vector.
      result.push_back(maxHeap.top().second);
      // Remove the top element to access the next one in the following iteration.
      maxHeap.pop();
    }

    return result;
  }
};