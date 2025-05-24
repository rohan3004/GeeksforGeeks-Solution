class Solution {
  public:
    int sumSubstrings(string &s) {
        int n = s.size();
        long long res = 0;
        long long prev = 0;
        const int MOD = 1e9 + 7;  // Not strictly needed here, but often useful

        for (int i = 0; i < n; ++i) {
            int num = s[i] - '0';
            prev = prev * 10 + num * (i + 1);
            res += prev;
        }

        return static_cast<int>(res);
    }
};
