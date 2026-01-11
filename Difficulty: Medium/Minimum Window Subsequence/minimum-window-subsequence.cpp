#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();

        // Edge cases
        if (m == 0) return "";
        if (n < m) return "";

        // Precompute the next occurrence of each character.
        // next_occurrence[i][c] stores the index of character 'c' in s1 
        // at or after index i.
        vector<vector<int>> next_occurrence(n + 1, vector<int>(26, -1));

        // Fill table from right to left
        for (int i = n - 1; i >= 0; --i) {
            // Copy pointers from the next position
            for (int j = 0; j < 26; ++j) {
                next_occurrence[i][j] = next_occurrence[i + 1][j];
            }
            // Update the current character's position
            next_occurrence[i][s1[i] - 'a'] = i;
        }

        int min_len = INT_MAX;
        int start_index = -1;

        // Iterate through s1 to find every possible start of the subsequence
        for (int i = 0; i < n; ++i) {
            // If the current char in s1 matches the first char of s2, check this window
            if (s1[i] == s2[0]) {
                int curr = i;
                bool valid = true;

                // Try to match the rest of s2 using the jump table
                for (int k = 1; k < m; ++k) {
                    int char_idx = s2[k] - 'a';
                    // Look for the next char strictly after 'curr'
                    int next_pos = next_occurrence[curr + 1][char_idx];

                    if (next_pos == -1) {
                        valid = false;
                        break; 
                    }
                    curr = next_pos;
                }

                if (valid) {
                    int current_len = curr - i + 1;
                    // Update if we found a strictly smaller window
                    if (current_len < min_len) {
                        min_len = current_len;
                        start_index = i;
                    }
                }
            }
        }

        if (start_index == -1) {
            return "";
        }

        return s1.substr(start_index, min_len);
    }
};