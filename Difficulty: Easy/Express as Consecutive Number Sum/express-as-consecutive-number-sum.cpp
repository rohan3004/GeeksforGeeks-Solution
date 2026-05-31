class Solution {
public:
    bool isSumOfConsecutive(int n) {
        // A number can be expressed as a sum of consecutive positive numbers
        // if and only if it is NOT a power of 2.
        
        // Bitwise trick: (n & (n - 1)) == 0 checks if a number is a power of 2.
        // We return true if it is NOT a power of 2.
        return (n & (n - 1)) != 0;
    }
};