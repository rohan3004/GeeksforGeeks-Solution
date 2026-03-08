#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int max_val = 0;
        
        // Find the maximum element in the array
        for (int x : arr) {
            max_val = max(max_val, x);
        }
        
        // Create an array to map the presence of each number
        vector<bool> present(max_val + 1, false);
        for (int x : arr) {
            present[x] = true;
        }
        
        // Check for all possible combinations of 'a' and 'b'
        for (int a = 1; a <= max_val; a++) {
            // Only proceed if 'a' is actually in our original array
            if (!present[a]) continue;
            
            for (int b = a + 1; b <= max_val; b++) {
                // Only proceed if 'b' is in our original array
                if (!present[b]) continue;
                
                // Calculate expected c^2
                int c_sq = a * a + b * b;
                int c = sqrt(c_sq);
                
                // Check if c is a perfect square, fits in our max range, and exists in the array
                if (c * c == c_sq && c <= max_val && present[c]) {
                    return true;
                }
            }
        }
        
        return false;
    }
};