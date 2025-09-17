#include <string>
#include <stack>
#include <cctype>

class Solution {
public:
    /**
     * @brief Decodes a string with the pattern k[substring].
     * * This function uses two stacks to handle nested encoded patterns.
     * One stack stores the repetition counts (k), and the other stores
     * the string being built before a new encoded part starts.
     * * @param s The encoded string.
     * @return The decoded string.
     */
    std::string decodedString(std::string &s) {
        // Stack to store repetition counts (k).
        std::stack<int> numStack;
        // Stack to store strings before a '['.
        std::stack<std::string> strStack;
        
        std::string currentString = "";
        int currentNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                // Build the number which can be multi-digit.
                currentNum = currentNum * 10 + (c - '0');
            } else if (c == '[') {
                // Push the current state to the stacks and reset.
                numStack.push(currentNum);
                strStack.push(currentString);
                
                currentNum = 0;
                currentString = "";
            } else if (c == ']') {
                // Pop the last number and string to decode the current part.
                int k = numStack.top();
                numStack.pop();
                
                std::string temp = "";
                // Repeat the current substring k times.
                for (int i = 0; i < k; ++i) {
                    temp += currentString;
                }
                
                // Prepend the string from the outer scope.
                currentString = strStack.top() + temp;
                strStack.pop();
            } else {
                // Append the character to the current substring.
                currentString += c;
            }
        }
        
        return currentString;
    }
};