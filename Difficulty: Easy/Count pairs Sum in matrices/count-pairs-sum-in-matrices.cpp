class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        int n = mat1.size();
        if (n == 0) return 0;

        int N = n * n;
        int lo = 0, hi = N - 1;
        int count = 0;

        // Helper lambdas to map a flat index [0..N-1] to (row, col)
        auto get1 = [&](int idx) {
            int r = idx / n;
            int c = idx % n;
            return mat1[r][c];
        };
        auto get2 = [&](int idx) {
            int r = idx / n;
            int c = idx % n;
            return mat2[r][c];
        };

        while (lo < N && hi >= 0) {
            int a = get1(lo);
            int b = get2(hi);
            int sum = a + b;

            if (sum == x) {
                count++;
                lo++;
                hi--;
            }
            else if (sum < x) {
                lo++;
            }
            else {  // sum > x
                hi--;
            }
        }

        return count;
    }
};
