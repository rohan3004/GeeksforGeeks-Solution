#include <string>
#include <algorithm>
#include <vector>

class Solution {
  public:
    string largestSwap(string &s) {
        // Create a copy of s and sort it in descending order to represent the ideal string.
        string sorted_s = s;
        sort(sorted_s.rbegin(), sorted_s.rend());

        int first_mismatch_idx = -1;
        
        // Find the first position from the left where s differs from its ideal sorted version.
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != sorted_s[i]) {
                first_mismatch_idx = i;
                break;
            }
        }

        // If no mismatch is found, the string is already the largest possible.
        if (first_mismatch_idx == -1) {
            return s;
        }

        // The character that should be at the mismatch position.
        char target_char = sorted_s[first_mismatch_idx];
        int swap_target_idx = -1;

        // Find the rightmost occurrence of the target character in the original string.
        for (int j = s.length() - 1; j >= 0; --j) {
            if (s[j] == target_char) {
                swap_target_idx = j;
                break;
            }
        }

        // Perform the single, optimal swap.
        swap(s[first_mismatch_idx], s[swap_target_idx]);
        
        return s;
    }
};