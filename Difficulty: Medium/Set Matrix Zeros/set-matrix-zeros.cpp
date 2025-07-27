class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size();
        if (n == 0) return;
        int m = mat[0].size();
        if (m == 0) return;

        bool firstRowZero = false;
        bool firstColZero = false;

        // 1. Check if the first row needs to be zeroed
        for (int j = 0; j < m; ++j) {
            if (mat[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // 2. Check if the first column needs to be zeroed
        for (int i = 0; i < n; ++i) {
            if (mat[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // 3. Use the first row & column as markers for the rest of the matrix
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        // 4. Modify the inner matrix based on the markers
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        // 5. Zero out the first row if needed
        if (firstRowZero) {
            for (int j = 0; j < m; ++j) {
                mat[0][j] = 0;
            }
        }

        // 6. Zero out the first column if needed
        if (firstColZero) {
            for (int i = 0; i < n; ++i) {
                mat[i][0] = 0;
            }
        }
    }
};