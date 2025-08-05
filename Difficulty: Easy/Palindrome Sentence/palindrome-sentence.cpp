#include <string>
#include <cctype>

class Solution {
 public:
  /**
   * @brief Checks if a string is a palindrome sentence.
   * * A palindrome sentence reads the same backward as forward after converting
   * all uppercase letters to lowercase and removing all non-alphanumeric
   * characters.
   * * @param s The input string, passed by reference.
   * @return true if the string is a palindrome sentence, false otherwise.
   */
  bool isPalinSent(string &s) {
    int left = 0;
    int right = s.length() - 1;

    // Use two pointers, one from the start and one from the end,
    // moving towards the center.
    while (left < right) {
      // Advance the left pointer until it points to an alphanumeric character.
      // The `left < right` check is crucial to prevent pointers from crossing.
      while (left < right && !isalnum(s[left])) {
        left++;
      }

      // Advance the right pointer until it points to an alphanumeric character.
      while (left < right && !isalnum(s[right])) {
        right--;
      }

      // Compare the characters in a case-insensitive manner.
      if (tolower(s[left]) != tolower(s[right])) {
        // If characters do not match, it's not a palindrome sentence.
        return false;
      }
      
      // Move pointers inward to check the next pair of characters.
      left++;
      right--;
    }
    
    // If the loop completes without finding any mismatches,
    // the sentence is a palindrome.
    return true;
  }
};