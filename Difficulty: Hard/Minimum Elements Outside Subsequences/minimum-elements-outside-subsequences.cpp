#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    // memo[i][last_inc][last_dec]
    // i: index up to 105
    // last_inc: values up to 100 (0 used as base/empty) -> size 105
    // last_dec: values up to 100 (101 used as base/empty) -> size 105
    int memo[105][105][105];

    int solve(int i, int last_inc, int last_dec, const vector<int>& arr) {
        // Base case: If we've considered all elements
        if (i == arr.size()) {
            return 0;
        }

        // Return already computed overlapping subproblem
        if (memo[i][last_inc][last_dec] != -1) {
            return memo[i][last_inc][last_dec];
        }

        // Option 1: Skip the current element entirely
        int max_picked = solve(i + 1, last_inc, last_dec, arr);

        // Option 2: Add the current element to the strictly increasing subsequence
        if (arr[i] > last_inc) {
            max_picked = max(max_picked, 1 + solve(i + 1, arr[i], last_dec, arr));
        }

        // Option 3: Add the current element to the strictly decreasing subsequence
        if (arr[i] < last_dec) {
            max_picked = max(max_picked, 1 + solve(i + 1, last_inc, arr[i], arr));
        }

        // Save and return the max elements that can be picked
        return memo[i][last_inc][last_dec] = max_picked;
    }

public:
    int minCount(vector<int>& arr) {
        // Initialize memoization table with -1
        memset(memo, -1, sizeof(memo));

        // max_included holds the maximum elements we can successfully pack into the 2 subsequences
        int max_included = solve(0, 0, 101, arr);

        // Total elements - max elements we could include = minimum left out
        return arr.size() - max_included;
    }
};