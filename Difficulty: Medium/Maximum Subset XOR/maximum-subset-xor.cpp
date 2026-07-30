#include <vector>

using namespace std;

class Solution {
public:
    int maxSubsetXOR(vector<int> &arr) {
        // basis[i] will store a number whose most significant set bit is at position i
        int basis[32] = {0};
        
        // Step 1: Build the linear basis
        for (int x : arr) {
            for (int i = 31; i >= 0; i--) {
                // If the i-th bit of x is set
                if ((x >> i) & 1) {
                    if (!basis[i]) {
                        basis[i] = x;
                        break;
                    }
                    // Cancel the i-th bit and continue
                    x ^= basis[i];
                }
            }
        }
        
        // Step 2: Greedily calculate the maximum XOR
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            // If XORing basis[i] increases the overall result, include it
            if ((res ^ basis[i]) > res) {
                res ^= basis[i];
            }
        }
        
        return res;
    }
};