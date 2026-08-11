#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries, int k) {
        int n = mat.size();
        if (n == 0) return {};
        int m = mat[0].size();
        
        // Step 1: Precompute the 2D prefix sum array
        // pref[i][j] will store the sum of ones in the submatrix from (0,0) to (i-1, j-1)
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i + 1][j + 1] = mat[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }
        
        vector<int> res;
        res.reserve(queries.size());
        
        // Step 2: Process each query using Binary Search
        for (const auto& q : queries) {
            int r_c = q[0];
            int c_c = q[1];
            
            // Maximum radius based on the shortest distance to matrix boundaries
            int max_r = min({r_c, c_c, n - 1 - r_c, m - 1 - c_c});
            
            int low = 0, high = max_r, ans = -1;
            
            while (low <= high) {
                int mid = low + (high - low) / 2;
                
                // Boundaries of the square submatrix with radius 'mid'
                int r1 = r_c - mid;
                int c1 = c_c - mid;
                int r2 = r_c + mid;
                int c2 = c_c + mid;
                
                // Calculate the number of 1s in the square using the prefix sum
                int ones = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
                
                // If the sum of ones is within the limit k, we look for a potentially larger square
                if (ones <= k) {
                    ans = mid;
                    low = mid + 1;
                } 
                // If it exceeds k, we have to shrink the square
                else {
                    high = mid - 1;
                }
            }
            
            // Step 3: Extracting findings
            if (ans == -1) {
                res.push_back(-1);
            } else {
                res.push_back(2 * ans + 1);
            }
        }
        
        return res;
    }
};