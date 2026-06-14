#include <vector>
using namespace std;

class Solution {
public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int r = 0, c = 0;
        int dir = 0; // 0 = Right, 1 = Down, 2 = Left, 3 = Up
        
        // Track the last valid cell before exiting the matrix
        int prev_r = 0, prev_c = 0;
        
        while (r >= 0 && r < n && c >= 0 && c < m) {
            // Save current position before moving
            prev_r = r;
            prev_c = c;
            
            // If we hit a 1, turn clockwise and flip it to 0
            if (mat[r][c] == 1) {
                mat[r][c] = 0;
                dir = (dir + 1) % 4;
            }
            
            // Move to the next cell based on the current direction
            if (dir == 0) {
                c++;      // Move Right
            } else if (dir == 1) {
                r++;      // Move Down
            } else if (dir == 2) {
                c--;      // Move Left
            } else if (dir == 3) {
                r--;      // Move Up
            }
        }
        
        // Return the last valid cell coordinates
        return {prev_r, prev_c};
    }
};