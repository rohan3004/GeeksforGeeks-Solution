#include <string>
#include <stack>

using namespace std;

class Solution {
 public:
  /**
   * @brief Calculates the minimum number of parentheses to add to make a string valid.
   * * @param s The input string consisting of '(' and ')'.
   * @return The minimum number of parentheses to add.
   */
  int minParentheses(string& s) {
    // 'balance' will track the number of open parentheses '(' that are waiting for a matching ')'
    int balance = 0;
    
    // 'insertions' will count the number of parentheses we need to insert.
    int insertions = 0;

    // Iterate through each character of the string.
    for (char c : s) {
      if (c == '(') {
        // We found an opening parenthesis, so we increment the balance.
        balance++;
      } else { // c == ')'
        // We found a closing parenthesis.
        if (balance > 0) {
          // If there's a positive balance, it means there's an open parenthesis
          // waiting to be matched. We use this ')' to match it.
          balance--;
        } else {
          // If the balance is zero, this ')' has no matching '('.
          // We must insert a '(' to make it valid.
          insertions++;
        }
      }
    }

    // After iterating through the string, if 'balance' is still greater than zero,
    // it represents the number of open parentheses that were never closed.
    // We need to insert a ')' for each of them.
    // The total insertions is the sum of insertions for unmatched ')' and unmatched '('.
    return insertions + balance;
  }
};
