#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstring(string& s) {
        int n = s.length();
        
        // We use an offset because prefix sums can go negative (down to -n).
        // By adding (n + 1) to our current prefix sum, we safely map -n to 1, avoiding negative indices.
        int offset = n + 1;
        vector<int> count(2 * n + 3, 0);
        
        // Initialize the base case: a prefix sum of 0 occurs exactly once before the string starts.
        count[0 + offset] = 1;
        
        int curr = 0;           // Tracks the current prefix sum
        int valid_pairs = 0;    // Tracks how many previous prefix sums are strictly less than `curr`
        int ans = 0;            // Total count of valid substrings

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                curr++;
                // Our sum went up, so the old current sum (curr - 1) is now strictly less than curr.
                // We add its frequency to our valid pairs.
                valid_pairs += count[curr - 1 + offset];
            } else {
                curr--;
                // Our sum went down, so the new current sum (curr) is no longer strictly less than itself.
                // We subtract its frequency from our valid pairs.
                valid_pairs -= count[curr + offset];
            }
            
            // Add the dynamically tracked valid pairs to our total answer
            ans += valid_pairs;
            
            // Record the occurrence of this new prefix sum
            count[curr + offset]++;
        }

        return ans;
    }
};