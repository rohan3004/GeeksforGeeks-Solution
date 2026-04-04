#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    vector<string> graycode(int n) {
        vector<string> result;
        int total = 1 << n; // Total number of bit patterns is 2^n
        
        for (int i = 0; i < total; i++) {
            // The formula to find the i-th Gray code is: i XOR (i / 2)
            int gray = i ^ (i >> 1);
            
            // Convert the integer 'gray' to an n-bit binary string
            string current_pattern = "";
            for (int j = n - 1; j >= 0; j--) {
                if ((gray >> j) & 1) {
                    current_pattern += '1';
                } else {
                    current_pattern += '0';
                }
            }
            
            result.push_back(current_pattern);
        }
        
        return result;
    }
};