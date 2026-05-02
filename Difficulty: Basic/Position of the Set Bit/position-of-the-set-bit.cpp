#include <cmath>

class Solution {
  public:
    int findPosition(int n) {
        // If n is 0 or has more than one set bit, return -1
        if (n <= 0 || (n & (n - 1)) != 0) {
            return -1;
        }
        
        // Calculate the 1-based position of the set bit
        return log2(n) + 1;
    }
};