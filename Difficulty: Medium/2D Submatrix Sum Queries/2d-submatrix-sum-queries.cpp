class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Step 1: Create and fill the 2D Prefix Sum array
        // pref[i][j] will store sum of rectangle from (0,0) to (i,j)
        vector<vector<int>> pref(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Start with the current element
                pref[i][j] = mat[i][j];
                
                // Add the sum of the top rectangle
                if (i > 0) pref[i][j] += pref[i-1][j];
                
                // Add the sum of the left rectangle
                if (j > 0) pref[i][j] += pref[i][j-1];
                
                // Subtract the intersection (added twice above)
                if (i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];
            }
        }
        
        // Step 2: Process each query in O(1) time
        vector<int> result;
        for (const auto& q : queries) {
            int r1 = q[0];
            int c1 = q[1];
            int r2 = q[2];
            int c2 = q[3];
            
            // Start with the full area from (0,0) to (r2, c2)
            int sum = pref[r2][c2];
            
            // Subtract area above the submatrix (if valid)
            if (r1 > 0) sum -= pref[r1-1][c2];
            
            // Subtract area to the left of the submatrix (if valid)
            if (c1 > 0) sum -= pref[r2][c1-1];
            
            // Add back the top-left intersection (subtracted twice)
            if (r1 > 0 && c1 > 0) sum += pref[r1-1][c1-1];
            
            result.push_back(sum);
        }
        
        return result;
    }
};