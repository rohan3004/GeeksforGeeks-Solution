#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int left = 0;
        int right = 0;
        int distinct_count = 0;
        int total_subarrays = 0;
        unordered_map<int, int> freq_map;

        for (right = 0; right < arr.size(); ++right) {
            // Add the current element to the window
            freq_map[arr[right]]++;
            
            // If it's a new distinct element, increment the count
            if (freq_map[arr[right]] == 1) {
                distinct_count++;
            }

            // If distinct count exceeds k, shrink the window from the left
            while (distinct_count > k) {
                freq_map[arr[left]]--;
                if (freq_map[arr[left]] == 0) {
                    distinct_count--;
                }
                left++;
            }

            // All subarrays ending at 'right' and starting from 'left' to 'right' are valid.
            // There are exactly (right - left + 1) such subarrays.
            total_subarrays += (right - left + 1);
        }

        return total_subarrays;
    }
};