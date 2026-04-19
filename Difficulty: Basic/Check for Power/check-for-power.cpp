class Solution {
public:
    bool isPower(int x, int y) {
        // A power of 1 can only ever be 1
        if (x == 1) {
            return y == 1;
        }
        
        // Keep dividing y by x as long as there is no remainder
        while (y % x == 0) {
            y /= x;
        }
        
        // If we successfully divided it down to 1, it's a perfect power
        return y == 1;
    }
};