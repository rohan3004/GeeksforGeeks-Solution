#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
  /**
   * @brief A recursive helper function to generate binary strings.
   * * @param n The target length of the binary strings.
   * @param current The string being built in the current recursive path.
   * @param result A reference to the vector to store the final strings.
   */
  void generate(int n, std::string current, std::vector<std::string>& result) {
    // Base Case: If the current string's length is equal to n,
    // it's a valid combination, so add it to the result vector.
    if (current.length() == n) {
      result.push_back(current);
      return;
    }

    // Recursive Step: Explore two possibilities for the next character.
    
    // 1. Append '0' and recurse.
    generate(n, current + '0', result);
    
    // 2. Append '1' and recurse.
    generate(n, current + '1', result);
  }

public:
  /**
   * @brief Generates all binary strings of length n in ascending order.
   * * @param n The length of the binary strings to generate.
   * @return A vector of strings containing all possible binary strings.
   */
  std::vector<std::string> binstr(int n) {
    std::vector<std::string> result;
    // Initial call to the recursive helper with an empty string.
    generate(n, "", result);
    return result;
  }
};