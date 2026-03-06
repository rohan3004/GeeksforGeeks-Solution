class Solution {
public:
    string minWindow(string &s, string &p) {
        int n = s.length();
        int m = p.length();
        if (m > n) return "";

        // Frequency maps for characters in p and the current window
        int p_freq[26] = {0};
        int window_freq[26] = {0};
        
        for (char c : p) p_freq[c - 'a']++;

        int left = 0, min_len = INT_MAX, start_idx = -1;
        int count = 0; // Number of characters currently satisfied in the window

        for (int right = 0; right < n; right++) {
            int char_idx = s[right] - 'a';
            window_freq[char_idx]++;

            // If the current character is needed and its count is within limits
            if (p_freq[char_idx] != 0 && window_freq[char_idx] <= p_freq[char_idx]) {
                count++;
            }

            // If the window contains all characters of p
            if (count == m) {
                // Try to shrink the window from the left
                while (p_freq[s[left] - 'a'] == 0 || window_freq[s[left] - 'a'] > p_freq[s[left] - 'a']) {
                    window_freq[s[left] - 'a']--;
                    left++;
                }

                // Update the minimum window
                int window_size = right - left + 1;
                if (window_size < min_len) {
                    min_len = window_size;
                    start_idx = left;
                }
            }
        }

        return (start_idx == -1) ? "" : s.substr(start_idx, min_len);
    }
};