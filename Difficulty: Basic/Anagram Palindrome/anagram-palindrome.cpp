class Solution {
  public:
    bool canFormPalindrome(string &s) {
        int counts[26] = {0};
        
        // Count the frequency of each character
        for (char c : s) {
            counts[c - 'a']++;
        }
        
        int oddCount = 0;
        
        // Count how many characters have an odd frequency
        for (int count : counts) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }
        
        // It can be a palindrome if at most one character has an odd frequency
        return oddCount <= 1;
    }
};