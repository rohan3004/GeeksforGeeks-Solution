#include <vector>

using namespace std;

class Solution {
public:
    bool isToeplitz(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        // Iterate through all elements except the last row and last column
        for (int i = 0; i < rows - 1; ++i) {
            for (int j = 0; j < cols - 1; ++j) {
                // If an element is not equal to its bottom-right neighbor, it's not Toeplitz
                if (mat[i][j] != mat[i + 1][j + 1]) {
                    return false;
                }
            }
        }
        
        // If all checks pass, it is a Toeplitz matrix
        return true;
    }
};