#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        sort(arr.begin(), arr.end());
        // dp[i] stores the best divisible-subset (ascending-sorted) ending at i
        vector<vector<int>> dp(n);

        vector<int> best = {arr[0]};
        dp[0] = {arr[0]};

        for (int i = 1; i < n; ++i) {
            // start with the trivial subset [arr[i]]
            dp[i] = {arr[i]};

            // try extending any j < i
            for (int j = 0; j < i; ++j) {
                if (arr[i] % arr[j] == 0) {
                    // candidate = dp[j] followed by arr[i]
                    vector<int> cand = dp[j];
                    cand.push_back(arr[i]);

                    // choose cand if it's longer, or same length but lex-greater
                    if (cand.size() > dp[i].size() ||
                        (cand.size() == dp[i].size() && cand > dp[i])) {
                        dp[i] = move(cand);
                    }
                }
            }

            // update global best
            if (dp[i].size() > best.size() ||
                (dp[i].size() == best.size() && dp[i] > best)) {
                best = dp[i];       
                    
                }
        }

        return best;
    }
};
