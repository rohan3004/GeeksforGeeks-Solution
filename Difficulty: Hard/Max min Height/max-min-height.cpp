#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // Helper function to check if a minimum height of 'target' is achievable
    bool isPossible(vector<int>& arr, int n, int k, int w, long long target) {
        vector<long long> water(n, 0); // Stores water added starting at index i
        long long current_boost = 0;   // Current active water boost
        long long days_needed = 0;     // Total days used

        for (int i = 0; i < n; i++) {
            // If we are past the window width, remove the effect of the water 
            // added w days ago (it no longer covers the current index)
            if (i >= w) {
                current_boost -= water[i - w];
            }

            // Calculate current height including active boosts
            long long current_height = arr[i] + current_boost;

            // If height is less than target, we must water
            if (current_height < target) {
                long long deficit = target - current_height;
                
                // If we need more days than available, return false
                if (days_needed + deficit > k) {
                    return false;
                }

                // Apply water starting here
                water[i] = deficit;
                current_boost += deficit;
                days_needed += deficit;
            }
        }
        return true;
    }

    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();
        
        // Define Binary Search Range
        // Lower bound: min element (we can always achieve at least this)
        // Upper bound: max element + k (rough safe upper limit)
        long long low = *min_element(arr.begin(), arr.end());
        long long high = *max_element(arr.begin(), arr.end()) + (long long)k;
        long long ans = low;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isPossible(arr, n, k, w, mid)) {
                ans = mid;      // This height is possible, try for a higher one
                low = mid + 1;
            } else {
                high = mid - 1; // This height is not possible, try lower
            }
        }

        return (int)ans;
    }
};