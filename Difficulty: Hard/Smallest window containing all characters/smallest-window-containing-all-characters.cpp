#include <string>
#include <vector>
#include <climits>

class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // Edge case: if the pattern is longer than the string, no solution is possible.
        if (p.length() > s.length()) {
            return "";
        }

        // Create a frequency map for the characters in the pattern string 'p'.
        // We use a vector of size 256 to cover all possible ASCII characters.
        std::vector<int> p_map(256, 0);
        for (char c : p) {
            p_map[c]++;
        }

        int start = 0;              // The start pointer of the sliding window
        int required = p.length();  // The count of characters from 'p' we still need to find
        int min_len = INT_MAX;      // The length of the smallest valid window found so far
        int start_index = -1;       // The starting index of that smallest window

        // The 'end' pointer expands the window to the right
        for (int end = 0; end < s.length(); ++end) {
            char char_end = s[end];

            // If the character at 'end' is one we need (its count in p_map is > 0),
            // it means we've fulfilled one requirement.
            if (p_map[char_end] > 0) {
                required--;
            }
            // Decrement the count for the current character in our map.
            // This also handles surplus characters (the count will become negative).
            p_map[char_end]--;

            // When 'required' is 0, we have a valid window.
            // Now, we try to shrink it from the left to find the smallest one.
            while (required == 0) {
                int current_len = end - start + 1;

                // If this window is the smallest yet, update our result.
                if (current_len < min_len) {
                    min_len = current_len;
                    start_index = start;
                }

                // To shrink, we remove the character at 'start' from the window.
                char char_start = s[start];

                // We "give back" the character by incrementing its count in the map.
                p_map[char_start]++;

                // If the count of this character becomes positive again, it means
                // our window is no longer valid without it. So, we increment 'required'.
                if (p_map[char_start] > 0) {
                    required++;
                }

                // Move the start pointer to the right, effectively shrinking the window.
                start++;
            }
        }

        // If start_index was never updated, no valid window was found.
        if (start_index == -1) {
            return "";
        }

        // Return the smallest window found.
        return s.substr(start_index, min_len);
    }
};