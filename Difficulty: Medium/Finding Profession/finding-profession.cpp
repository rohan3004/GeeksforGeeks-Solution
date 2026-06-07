class Solution {
public:
    string profession(int level, int pos) {
        // Convert to 0-based index
        int p = pos - 1;
        
        // Count the number of set bits (1s) in the binary representation of p
        int setBits = 0;
        while (p > 0) {
            setBits += (p & 1); // Add the last bit to our count
            p >>= 1;            // Shift right by 1 to check the next bit
        }
        
        // Alternatively, in C++ you can just use the built-in compiler function:
        // int setBits = __builtin_popcount(pos - 1);
        
        // Even number of set bits means Engineer, Odd means Doctor
        if (setBits % 2 == 0) {
            return "Engineer";
        } else {
            return "Doctor";
        }
    }
};