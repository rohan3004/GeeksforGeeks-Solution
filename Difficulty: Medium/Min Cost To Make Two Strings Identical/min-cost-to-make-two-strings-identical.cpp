#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        int m = s1.length();
        int n = s2.length();

        // We only need two rows to compute LCS, optimizing space to O(N)
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            // Move to the next row
            prev = curr;
        }

        // Length of the Longest Common Subsequence
        int lcs_len = prev[n];

        // Calculate and return the minimum cost
        return (m - lcs_len) * costS1 + (n - lcs_len) * costS2;
    }
};