class Solution {
 public:
  int countPS(string &s) {
    int n = s.length();
    // If the string length is less than 2, no such substring is possible.
    if (n < 2) {
      return 0;
    }

    int count = 0;

    // Iterate through each character of the string to consider it as a center.
    for (int i = 0; i < n; ++i) {
      // Find all ODD length palindromes with s[i] as the center.
      // We start expanding from the characters adjacent to the center s[i].
      // Pointers start at i-1 and i+1.
      int left = i - 1;
      int right = i + 1;
      while (left >= 0 && right < n && s[left] == s[right]) {
        count++; // Found a palindrome of length > 1
        left--;
        right++;
      }

      // Find all EVEN length palindromes with the center between s[i] and s[i+1].
      // Pointers start at i and i+1.
      left = i;
      right = i + 1;
      while (left >= 0 && right < n && s[left] == s[right]) {
        count++; // Found a palindrome of length > 1
        left--;
        right++;
      }
    }
    return count;
  }
};