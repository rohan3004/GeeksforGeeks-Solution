class Solution {
public:
    int getCount(int n) {
        // adjacency list for each key: itself + up/down/left/right
        static const vector<vector<int>> moves = {
            /* 0 */ {0,8},
            /* 1 */ {1,2,4},
            /* 2 */ {2,1,3,5},
            /* 3 */ {3,2,6},
            /* 4 */ {4,1,5,7},
            /* 5 */ {5,2,4,6,8},
            /* 6 */ {6,3,5,9},
            /* 7 */ {7,4,8},
            /* 8 */ {8,5,7,9,0},
            /* 9 */ {9,6,8}
        };
        
        // dp[d] = # of sequences of current length ending at digit d
        vector<int> dp(10, 1), next_dp(10);
        // length = 1: exactly 1 way to have a 1-digit sequence at each key
        
        for (int len = 2; len <= n; ++len) {
            fill(next_dp.begin(), next_dp.end(), 0);
            for (int d = 0; d <= 9; ++d) {
                for (int nei : moves[d]) {
                    next_dp[d] += dp[nei];
                }
            }
            dp.swap(next_dp);
        }
        
        // sum over all ending digits
        int total = 0;
        for (int d = 0; d <= 9; ++d)
            total += dp[d];
        return total;
    }
};
