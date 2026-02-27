class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        int count = 0;

        // 1. Build 2D Prefix Sum Array
        // Using (n+1) x (m+1) to handle boundary conditions easily
        vector<vector<long long>> pref(n + 1, vector<long long>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = mat[i - 1][j - 1] 
                             + pref[i - 1][j] 
                             + pref[i][j - 1] 
                             - pref[i - 1][j - 1];
            }
        }

        // 2. Iterate through all possible square submatrices
        // s is the side length of the square
        for (int s = 1; s <= min(n, m); s++) {
            for (int i = 1; i <= n - s + 1; i++) {
                for (int j = 1; j <= m - s + 1; j++) {
                    int r2 = i + s - 1;
                    int c2 = j + s - 1;
                    
                    // Calculate sum of square [i, j] to [r2, c2]
                    long long currentSum = pref[r2][c2] 
                                         - pref[i - 1][c2] 
                                         - pref[r2][j - 1] 
                                         + pref[i - 1][j - 1];

                    if (currentSum == x) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};