#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Checks if it's possible to make 'm' bouquets of size 'k' by a given 'day'.
     * * @param arr The array of bloom days.
     * @param k The number of adjacent flowers per bouquet.
     * @param m The required number of bouquets.
     * @param day The current day to check against.
     * @return true if 'm' bouquets can be made, false otherwise.
     */
    bool canMakeBouquets(const vector<int>& arr, int k, int m, int day) {
        int bouquets = 0;
        int adjacent_flowers = 0;
        
        // Iterate through all the flowers
        for (int bloom_day : arr) {
            // Check if the flower at the current position has bloomed
            if (bloom_day <= day) {
                adjacent_flowers++;
            } else {
                // If not bloomed, it breaks the adjacency streak
                adjacent_flowers = 0;
            }
            
            // If we have collected k adjacent flowers, we can make a bouquet
            if (adjacent_flowers == k) {
                bouquets++;
                adjacent_flowers = 0; // Reset for the next bouquet
            }
        }
        
        // Return true if we were able to make at least 'm' bouquets
        return bouquets >= m;
    }

    /**
     * @brief Finds the minimum number of days to make 'm' bouquets of size 'k'.
     * * @param arr The array of bloom days for each flower.
     * @param k The number of adjacent flowers required for one bouquet.
     * @param m The total number of bouquets needed.
     * @return The minimum number of days, or -1 if impossible.
     */
    int minDaysBloom(vector<int>& arr, int k, int m) {
        // --- Edge Case ---
        // If the total flowers required is more than available, it's impossible.
        // Use long long to prevent potential integer overflow for m * k.
        if ((long long)m * k > arr.size()) {
            return -1;
        }
        
        // --- Binary Search Setup ---
        // The search space for the number of days is between the earliest and latest bloom day.
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;
        
        // --- Binary Search on the Answer (Days) ---
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if it's possible to make the bouquets by day 'mid'
            if (canMakeBouquets(arr, k, m, mid)) {
                // 'mid' is a possible answer. Try to find an even earlier day.
                ans = mid;
                high = mid - 1;
            } else {
                // Not possible by day 'mid'. Need to wait longer.
                low = mid + 1;
            }
        }
        
        return ans;
    }
};
