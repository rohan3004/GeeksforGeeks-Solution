#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxCharGap(string &s) {
        // Array to store the first occurrence index of each character.
        // Size is 26 for lowercase English letters. Initialized to -1.
        vector<int> first_occurrence(26, -1);
        
        int max_gap = -1;
        
        for (int i = 0; i < s.length(); ++i) {
            int char_idx = s[i] - 'a'; // Map 'a'-'z' to 0-25
            
            if (first_occurrence[char_idx] == -1) {
                // If it's the first time seeing this character, record its index
                first_occurrence[char_idx] = i;
            } else {
                // If we've seen it before, calculate the gap and update max_gap
                int current_gap = i - first_occurrence[char_idx] - 1;
                max_gap = max(max_gap, current_gap);
            }
        }
        
        return max_gap;
    }
};