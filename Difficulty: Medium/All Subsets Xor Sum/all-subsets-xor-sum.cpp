#include <vector>
#include <cmath>

class Solution {
  public:
    int subsetXORSum(std::vector<int>& arr) {
        int n = arr.size();
        
        // Edge case: if array is empty (though constraints say size >= 1)
        if (n == 0) return 0;
        
        int bitwiseOr = 0;
        
        // Calculate the Bitwise OR of all elements
        for (int num : arr) {
            bitwiseOr |= num;
        }
        
        // The formula is: OR_Sum * 2^(n-1)
        // We use bitwise left shift '<<' to multiply by powers of 2 efficiently.
        return bitwiseOr << (n - 1);
    }
};