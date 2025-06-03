#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // Count number of substrings with at most K distinct characters
    long long countAtMost(const string &s, int K) {
        int n = s.size();
        vector<int> freq(26, 0);
        int distinct = 0;
        long long ans = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            if (freq[s[right] - 'a']++ == 0) {
                // We just introduced a new character
                distinct++;
            }
            // Shrink window until we have at most K distinct
            while (distinct > K) {
                if (--freq[s[left] - 'a'] == 0) {
                    distinct--;
                }
                left++;
            }
            // Now [left..right] has at most K distinct; every substring ending at 'right'
            // and starting anywhere in [left..right] is valid.
            ans += (right - left + 1);
        }

        return ans;
    }

  public:
    int countSubstr(string &s, int k) {
        if (k == 0) return 0;
        // # substrings with exactly k distinct = (# at most k) - (# at most (k-1))
        long long atMostK   = countAtMost(s, k);
        long long atMostK_1 = countAtMost(s, k - 1);
        return (int)(atMostK - atMostK_1);
    }
};
