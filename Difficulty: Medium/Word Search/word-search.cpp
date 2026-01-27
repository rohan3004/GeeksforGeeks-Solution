class Solution {
  public:
    int n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool dfs(int i, int j, int idx, vector<vector<char>> &mat, string &word) {
        if (idx == word.size()) return true;

        if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != word[idx])
            return false;

        char temp = mat[i][j];
        mat[i][j] = '#';  // mark visited

        for (int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (dfs(ni, nj, idx + 1, mat, word)) {
                mat[i][j] = temp;
                return true;
            }
        }

        mat[i][j] = temp;  // backtrack
        return false;
    }

    bool isWordExist(vector<vector<char>> &mat, string &word) {
        n = mat.size();
        m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, 0, mat, word))
                    return true;
            }
        }
        return false;
    }
};
