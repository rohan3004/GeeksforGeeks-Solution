class Solution {
public:
    int cuts(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        // Precompute powers of 5 up to 2^30 in binary
        unordered_set<string> powerOf5;
        for (long long p = 1; p <= (1LL << 30); p *= 5) {
            string binary = "";
            long long num = p;
            while (num > 0) {
                binary = (char)((num % 2) + '0') + binary;
                num /= 2;
            }
            powerOf5.insert(binary);
        }

        // DP
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                string sub = s.substr(j, i - j);
                if (sub[0] != '0' && powerOf5.count(sub)) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n] >= 1e9 ? -1 : dp[n];
    }
};
