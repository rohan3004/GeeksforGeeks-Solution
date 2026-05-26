#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minToggle(vector<int>& arr) {
        int total_zeros = 0;
        for (int num : arr) {
            if (num == 0) {
                total_zeros++;
            }
        }
        
        int ones_left = 0;
        int zeros_right = total_zeros;
        
        // Base case: if we switch all elements to 1s (split point at index 0)
        int min_toggles = ones_left + zeros_right;
        
        for (int num : arr) {
            if (num == 0) {
                zeros_right--; // A zero moves to the left side, needs no toggle
            } else {
                ones_left++;   // A one moves to the left side, needs to be toggled
            }
            
            // Check if the current split point requires fewer toggles
            min_toggles = min(min_toggles, ones_left + zeros_right);
        }
        
        return min_toggles;
    }
};