#include <vector>
#include <map>
#include <set>

class Solution {
 public:
  int sumOfModes(std::vector<int>& arr, int k) {
    int n = arr.size();
    if (k == 0 || n < k) {
      return 0;
    }

    // freq[i] stores the frequency of element i
    std::vector<int> freq(100001, 0);
    // freq_to_elements[f] stores a set of elements with frequency f
    std::map<int, std::set<int>> freq_to_elements;
    long long total_sum = 0;

    // Helper lambda to update the data structures
    auto update = [&](int val, int delta) {
      // Remove element from its old frequency group
      if (freq[val] > 0) {
        int old_freq = freq[val];
        freq_to_elements[old_freq].erase(val);
        if (freq_to_elements[old_freq].empty()) {
          freq_to_elements.erase(old_freq);
        }
      }

      // Update frequency
      freq[val] += delta;

      // Add element to its new frequency group
      if (freq[val] > 0) {
        int new_freq = freq[val];
        freq_to_elements[new_freq].insert(val);
      }
    };

    // Initialize the first window
    for (int i = 0; i < k; ++i) {
      update(arr[i], 1);
    }

    // Calculate mode for the first window and add to sum
    int mode = *(freq_to_elements.rbegin()->second.begin());
    total_sum += mode;

    // Slide the window from left to right
    for (int i = k; i < n; ++i) {
      // Add the new element entering the window from the right
      update(arr[i], 1);
      // Remove the old element leaving the window from the left
      update(arr[i - k], -1);

      // Find the mode of the new window and add to sum
      mode = *(freq_to_elements.rbegin()->second.begin());
      total_sum += mode;
    }

    // The problem specifies an int return type, though the sum can overflow.
    // We use long long for calculation and cast at the end as required.
    return (int)total_sum;
  }
};