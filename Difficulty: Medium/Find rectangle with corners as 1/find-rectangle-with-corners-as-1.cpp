class Solution {
  public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // For each pair of columns, we keep track of rows with 1s in both
        unordered_map<int, unordered_set<int>> columnPairs;

        for (int i = 0; i < n; ++i) {
            for (int c1 = 0; c1 < m; ++c1) {
                if (mat[i][c1] == 0) continue;
                for (int c2 = c1 + 1; c2 < m; ++c2) {
                    if (mat[i][c2] == 1) {
                        int key = c1 * 200 + c2; // Encode column pair
                        // If we've already seen this column pair in another row, it's a rectangle
                        if (columnPairs[key].size() > 0) {
                            return true;
                        }
                        columnPairs[key].insert(i);
                    }
                }
            }
        }
        return false;
    }
};
