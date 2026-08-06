class Solution {
public:
    int countMinOperations(vector<int>& arr) {
        int max_doubles = 0;
        int total_increments = 0;
        
        for (int x : arr) {
            if (x == 0) continue;
            
            // __builtin_popcount counts the number of set bits (1s) in the number.
            // Each set bit represents an increment operation needed.
            total_increments += __builtin_popcount(x);
            
            // __builtin_clz counts the number of leading zeros in a 32-bit integer.
            // 31 - __builtin_clz(x) gives the 0-indexed position of the highest set bit.
            // This represents the number of times we need to double the array for this element.
            int doubles_needed = 31 - __builtin_clz(x);
            max_doubles = max(max_doubles, doubles_needed);
        }
        
        return total_increments + max_doubles;
    }
};