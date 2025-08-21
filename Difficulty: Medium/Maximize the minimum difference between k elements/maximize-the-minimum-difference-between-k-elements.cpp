#include <vector>
#include <algorithm>

class Solution {
private:
    /**
     * @brief Checks if it's possible to select k elements with a minimum difference of 'diff'.
     * @param arr The sorted input array.
     * @param k The number of elements to select.
     * @param diff The minimum difference to check for.
     * @return True if possible, false otherwise.
     */
    bool isPossible(const std::vector<int>& arr, int k, int diff) {
        // We greedily select the first element.
        int count = 1;
        int last_selected = arr[0];

        // Iterate through the rest of the array to find other elements.
        for (size_t i = 1; i < arr.size(); ++i) {
            // If the current element is at least 'diff' away from the last one...
            if (arr[i] - last_selected >= diff) {
                // ...select it.
                count++;
                last_selected = arr[i];
                // Optimization: if we have already found k elements, we can stop early.
                if (count == k) {
                    return true;
                }
            }
        }
        // Check if we were able to select at least k elements.
        return count >= k;
    }

public:
    /**
     * @brief Finds the maximum possible minimum difference between k selected elements.
     * @param arr The input array of integers.
     * @param k The number of elements to select.
     * @return The maximized minimum difference.
     */
    int maxMinDiff(std::vector<int>& arr, int k) {
        // Sorting is essential for the greedy checking strategy.
        std::sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        // Define the search space for the binary search.
        int low = 0;
        int high = arr[n - 1] - arr[0];
        int ans = 0;
        
        // Binary search for the maximum possible minimum difference.
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossible(arr, k, mid)) {
                // If a difference of 'mid' is possible, it's a potential answer.
                // Try for a larger difference.
                ans = mid;
                low = mid + 1;
            } else {
                // If 'mid' is not possible, we must try a smaller difference.
                high = mid - 1;
            }
        }
        
        return ans;
    }
};