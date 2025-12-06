#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    // Memoization table to store results of subproblems
    // Constraints say n <= 1000, so 1001 is sufficient.
    int memo[1005][1005];

    int solve(vector<int>& arr, int i, int j) {
        // Base cases
        if (i > j) return 0;       // Invalid range
        if (i == j) return arr[i]; // Only one coin left, take it
        
        // Return already calculated value
        if (memo[i][j] != -1) return memo[i][j];

        // OPTION 1: We take the first coin (arr[i])
        // The opponent will play on [i+1, j]. 
        // Opponent chooses optimally to leave us with the MINIMUM of the next states.
        int pickFirst = arr[i] + min(solve(arr, i + 2, j), solve(arr, i + 1, j - 1));

        // OPTION 2: We take the last coin (arr[j])
        // The opponent will play on [i, j-1].
        // Opponent chooses optimally to leave us with the MINIMUM of the next states.
        int pickLast = arr[j] + min(solve(arr, i + 1, j - 1), solve(arr, i, j - 2));

        // We choose the option that gives us the MAXIMUM value
        return memo[i][j] = max(pickFirst, pickLast);
    }

public:
    int maximumAmount(vector<int> &arr) {
        int n = arr.size();
        // Initialize memo table with -1
        memset(memo, -1, sizeof(memo));
        
        return solve(arr, 0, n - 1);
    }
};