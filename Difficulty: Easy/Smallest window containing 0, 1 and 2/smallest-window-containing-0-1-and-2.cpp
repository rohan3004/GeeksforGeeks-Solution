#include <string>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int smallestSubstring(string s) {
        // Variables to store the most recent index of '0', '1', and '2'
        int last_zero = -1;
        int last_one = -1;
        int last_two = -1;
        
        int min_length = -1; // Initialize to -1 to handle cases where no substring is found

        for (int i = 0; i < s.length(); ++i) {
            // Update the last seen index for the current character
            if (s[i] == '0') {
                last_zero = i;
            } else if (s[i] == '1') {
                last_one = i;
            } else if (s[i] == '2') {
                last_two = i;
            }

            // If we have seen all three characters at least once
            if (last_zero != -1 && last_one != -1 && last_two != -1) {
                // The start of the valid window is the minimum of the three indices
                int start_index = min(last_zero, min(last_one, last_two));
                
                // Calculate the length of the current valid window
                int current_length = i - start_index + 1;
                
                // Update the minimum length found so far
                if (min_length == -1 || current_length < min_length) {
                    min_length = current_length;
                }
            }
        }

        return min_length;
    }
};