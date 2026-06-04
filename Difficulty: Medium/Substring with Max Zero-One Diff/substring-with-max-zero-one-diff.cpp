#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubstring(string &s) {
        int max_sum = -1e9; // Represents negative infinity
        int curr_sum = 0;
        
        for (char c : s) {
            // Treat '0' as +1 and '1' as -1
            int val = (c == '0') ? 1 : -1;
            curr_sum += val;
            
            // Update the maximum sum found so far
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
            }
            
            // If the running sum drops below 0, it's better to start a new substring
            if (curr_sum < 0) {
                curr_sum = 0;
            }
        }
        
        return max_sum;
    }
};