class Solution {
public:
    int findIndex(string &s) {
        int close_count = 0;
        
        // Count the total number of closing brackets
        for (char c : s) {
            if (c == ')') {
                close_count++;
            }
        }
        
        return close_count;
    }
};