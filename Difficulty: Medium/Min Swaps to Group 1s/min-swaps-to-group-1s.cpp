#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        int total_ones = 0;
        
        // 1. Count the total number of 1s in the array
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                total_ones++;
            }
        }
        
        // If there are no 1s, return -1 as per the problem description
        if (total_ones == 0) {
            return -1;
        }
        
        // 2. Count 1s in the first window of size 'total_ones'
        int current_ones = 0;
        for (int i = 0; i < total_ones; i++) {
            if (arr[i] == 1) {
                current_ones++;
            }
        }
        
        int max_ones = current_ones;
        
        // 3. Slide the window across the rest of the array
        for (int i = total_ones; i < n; i++) {
            // Add the new element entering the window
            if (arr[i] == 1) {
                current_ones++;
            }
            // Remove the old element exiting the window
            if (arr[i - total_ones] == 1) {
                current_ones--;
            }
            
            // Track the maximum number of 1s found in any window
            max_ones = max(max_ones, current_ones);
        }
        
        // Minimum swaps = Total 1s (window size) - Max 1s already in the best window
        return total_ones - max_ones;
    }
};