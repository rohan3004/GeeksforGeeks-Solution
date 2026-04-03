#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        vector<int> result;
        
        // Step 1: Traverse anti-diagonals starting from the first row
        for (int j = 0; j < n; ++j) {
            int row = 0;
            int col = j;
            
            // Move diagonally down-left
            while (row < n && col >= 0) {
                result.push_back(mat[row][col]);
                row++;
                col--;
            }
        }
        
        // Step 2: Traverse anti-diagonals starting from the last column
        // We start from row 1 because (0, n-1) was covered in Step 1
        for (int i = 1; i < n; ++i) {
            int row = i;
            int col = n - 1;
            
            // Move diagonally down-left
            while (row < n && col >= 0) {
                result.push_back(mat[row][col]);
                row++;
                col--;
            }
        }
        
        return result;
    }
};