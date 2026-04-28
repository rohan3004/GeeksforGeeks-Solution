#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubstr(string& s, int k) {
        int n = s.length();
        vector<int> count(26, 0); // To store frequencies of characters in the window
        int left = 0;
        int max_freq = 0;
        int max_len = 0;
        
        for (int right = 0; right < n; ++right) {
            // Add the current character to the window's frequency map
            count[s[right] - 'A']++;
            
            // Update the maximum frequency of a single character in the current window
            max_freq = max(max_freq, count[s[right] - 'A']);
            
            // Current window size is (right - left + 1)
            // If the characters we need to change exceed k, shrink the window
            if ((right - left + 1) - max_freq > k) {
                count[s[left] - 'A']--;
                left++;
            }
            
            // The window is guaranteed to be valid here, so we update max_len
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};