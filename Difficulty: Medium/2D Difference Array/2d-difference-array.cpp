class Solution {
 public:
  vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                  vector<vector<int>>& opr) {
    int n = mat.size();
    if (n == 0) return mat;
    int m = mat[0].size();
    if (m == 0) return mat;

    // Step 1: Create a difference matrix, initialized to zeros.
    vector<vector<int>> diff(n, vector<int>(m, 0));

    // Step 2: Apply all operations to the difference matrix.
    for (const auto& op : opr) {
      int v = op[0];
      int r1 = op[1];
      int c1 = op[2];
      int r2 = op[3];
      int c2 = op[4];

      diff[r1][c1] += v;

      if (c2 + 1 < m) {
        diff[r1][c2 + 1] -= v;
      }
      if (r2 + 1 < n) {
        diff[r2 + 1][c1] -= v;
      }
      if (r2 + 1 < n && c2 + 1 < m) {
        diff[r2 + 1][c2 + 1] += v;
      }
    }

    // Step 3: Compute the 2D prefix sum of the difference matrix.
    // First, a row-wise pass.
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        diff[i][j] += diff[i][j - 1];
      }
    }
    // Then, a column-wise pass.
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        diff[i][j] += diff[i - 1][j];
      }
    }

    // Step 4: Add the calculated differences to the original matrix.
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        mat[i][j] += diff[i][j];
      }
    }

    return mat;
  }
};