#include <string>
#include <unordered_map>

class Solution {
  public:
    int romanToDecimal(string &s) {
        // A map to store the integer values of Roman numerals.
        std::unordered_map<char, int> values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        // Initialize the result with the value of the last character.
        int result = values[s.back()];

        // Iterate through the string from the second-to-last character to the first.
        for (int i = s.length() - 2; i >= 0; i--) {
            // Get the value of the current character and the one to its right.
            int current_val = values[s[i]];
            int next_val = values[s[i + 1]];

            // If the current value is less than the next, it's a subtractive case.
            if (current_val < next_val) {
                result -= current_val;
            } 
            // Otherwise, it's an additive case.
            else {
                result += current_val;
            }
        }
        
        return result;
    }
};