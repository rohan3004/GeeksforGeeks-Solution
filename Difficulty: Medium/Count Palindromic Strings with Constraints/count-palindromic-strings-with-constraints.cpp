class Solution {
  public:
    int palindromicStrings(int n, int k) {
        long long mod = 1e9 + 7;
        long long total_ways = 0;

        long long current_P = 1;
        int c_current = 0;

        for (int L = 1; L <= n; ++L) {
            int c_needed = (L + 1) / 2;

            // If the current length needs an extra distinct character,
            // we multiply the permutation by the next available choice.
            if (c_needed > c_current) {
                current_P = (current_P * (k - c_current)) % mod;
                c_current++;
            }

            total_ways = (total_ways + current_P) % mod;
        }

        return total_ways;
    }
};