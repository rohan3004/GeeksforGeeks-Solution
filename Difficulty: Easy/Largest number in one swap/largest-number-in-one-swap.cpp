#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string largestSwap(string &s) {
        // Array to store the last occurrence index of each digit '0'-'9'
        vector<int> last_idx(10, -1);
        int n = s.length();
        
        // Step 1: Record the last occurrence of each digit
        for (int i = 0; i < n; ++i) {
            last_idx[s[i] - '0'] = i;
        }
        
        // Step 2: Find the first digit that can be swapped with a larger one
        for (int i = 0; i < n; ++i) {
            // Check for a larger digit from '9' down to 's[i] + 1'
            for (int d = 9; d > s[i] - '0'; --d) {
                // If a larger digit appears AFTER the current index 'i'
                if (last_idx[d] > i) {
                    // Swap them to make the string lexicographically largest
                    swap(s[i], s[last_idx[d]]);
                    return s; // At most ONE swap is allowed, so we are done
                }
            }
        }
        
        // If no swap can make the string larger, return it as is
        return s;
    }
};