class Solution {
public:
    int substrCount(string &s, int k) {
        int n = s.size();
        if (n < k) return 0;

        vector<int> freq(26, 0);
        int distinct = 0, ans = 0;

        // initialize the first window [0..k-1]
        for (int i = 0; i < k; ++i) {
            if (freq[s[i] - 'a']++ == 0) {
                ++distinct;
            }
        }
        if (distinct == k - 1) ++ans;

        // slide the window from i=k to n-1
        for (int i = k; i < n; ++i) {
            // remove s[i-k]
            int oldc = s[i - k] - 'a';
            if (--freq[oldc] == 0) {
                --distinct;
            }
            // add s[i]
            int newc = s[i] - 'a';
            if (freq[newc]++ == 0) {
                ++distinct;
            }

            if (distinct == k - 1) {
                ++ans;
            }
        }
        return ans;
    }
};
