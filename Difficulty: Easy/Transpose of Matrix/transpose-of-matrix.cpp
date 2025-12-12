class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // Iterate through the rows
        for (int i = 0; i < n; i++) {
            // Iterate through the columns starting from i + 1
            // to process only the upper triangle
            for (int j = i + 1; j < n; j++) {
                // Swap element at (i, j) with element at (j, i)
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        return mat;
    }
};