class Solution {
public:
    string chooseSwap(string &s) {
        // Array to store the first occurrence index of each character
        int first_idx[26];
        for (int i = 0; i < 26; ++i) {
            first_idx[i] = -1;
        }
        
        // Populate the first occurrences of every character
        for (int i = 0; i < s.length(); ++i) {
            if (first_idx[s[i] - 'a'] == -1) {
                first_idx[s[i] - 'a'] = i;
            }
        }
        
        // Find the first character that can be swapped with a smaller one
        for (int i = 0; i < s.length(); ++i) {
            // Check all characters strictly smaller than s[i]
            for (int j = 0; j < s[i] - 'a'; ++j) {
                // If a smaller character's FIRST appearance is after 'i'
                if (first_idx[j] > i) {
                    char c1 = s[i];
                    char c2 = j + 'a';
                    
                    // Execute the swap operation across the entire string
                    for (int k = 0; k < s.length(); ++k) {
                        if (s[k] == c1) s[k] = c2;
                        else if (s[k] == c2) s[k] = c1;
                    }
                    
                    // Only one swap operation is allowed, so we return immediately
                    return s;
                }
            }
        }
        
        // If no advantageous swap was found, return the original string
        return s;
    }
};