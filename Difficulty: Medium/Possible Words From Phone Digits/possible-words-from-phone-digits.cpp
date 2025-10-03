class Solution {
  public:
    // The mapping from digit to characters.
    // Index 0 and 1 are empty as they don't map to any letters.
    const vector<string> keypad = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    // Recursive helper function to generate words
    void solve(int index, const vector<int>& arr, string& currentCombination, vector<string>& result) {
        // Base case: If we have processed all digits, we have a complete word.
        if (index == arr.size()) {
            result.push_back(currentCombination);
            return;
        }
        
        // Get the current digit and its corresponding letters.
        int digit = arr[index];
        string letters = keypad[digit];
        
        // If a digit has no letters (like 0 or 1), just skip to the next digit.
        if (letters.empty()) {
            solve(index + 1, arr, currentCombination, result);
        } else {
            // Iterate through all possible characters for the current digit.
            for (char c : letters) {
                // 1. Choose: Append the character
                currentCombination.push_back(c);
                
                // 2. Explore: Recurse for the next digit
                solve(index + 1, arr, currentCombination, result);
                
                // 3. Un-choose (Backtrack): Remove the character to try the next one
                currentCombination.pop_back();
            }
        }
    }

    // Main function to initiate the process
    vector<string> possibleWords(vector<int>& arr) {
        vector<string> result;
        if (arr.empty()) {
            return result;
        }
        
        string currentCombination = "";
        solve(0, arr, currentCombination, result);
        
        return result;
    }
};