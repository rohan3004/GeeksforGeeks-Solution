class Solution {
  private:
    // Helper function to count substrings with AT MOST k distinct characters
    long long countAtMost(string& s, int k) {
        if (k < 0) return 0;
        
        int left = 0;
        long long count = 0;
        int distinct = 0;
        vector<int> freq(26, 0);
        
        for (int right = 0; right < s.size(); ++right) {
            // Add new character to window
            if (freq[s[right] - 'a'] == 0) {
                distinct++;
            }
            freq[s[right] - 'a']++;
            
            // If distinct characters exceed k, shrink window from left
            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0) {
                    distinct--;
                }
                left++;
            }
            
            // All substrings ending at 'right' and starting from 
            // 'left' to 'right' have at most k distinct characters.
            // The number of such substrings is length of the window.
            count += (right - left + 1);
        }
        return count;
    }

  public:
    long long countSubstr(string& s, int k) {
        // Exactly(k) = AtMost(k) - AtMost(k-1)
        return countAtMost(s, k) - countAtMost(s, k - 1);
    }
};