class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        int left = 0, maxLen = -1;
        unordered_map<char, int> freq;

        for (int right = 0; right < n; right++) {
            // Add current character to the window
            freq[s[right]]++;

            // If we have more than k distinct characters, shrink from the left
            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
            }

            // If we have exactly k characters, update maxLen
            if (freq.size() == k) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};