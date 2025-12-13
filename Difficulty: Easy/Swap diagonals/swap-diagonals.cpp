class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        int n = mat.size();
        
        // Iterate through each row
        for (int i = 0; i < n; i++) {
            // Swap the element at the major diagonal (i, i)
            // with the element at the minor diagonal (i, n - 1 - i)
            swap(mat[i][i], mat[i][n - 1 - i]);
        }
    }
};