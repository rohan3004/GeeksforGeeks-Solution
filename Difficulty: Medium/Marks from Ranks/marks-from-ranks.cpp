#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        int n = l.size();

        // pref[i] will store the total number of valid marks up to the i-th interval
        vector<long long> pref(n + 1, 0);
        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (r[i] - l[i] + 1);
        }

        vector<int> ans;
        for(int q : rank) {
            // Find the first index where cumulative marks are greater than or equal to the queried rank
            auto it = lower_bound(pref.begin(), pref.end(), (long long)q);

            // If it exceeds the maximum valid ranks, push -1 (handling edge cases)
            if (it == pref.end()) {
                ans.push_back(-1);
            } else {
                int idx = distance(pref.begin(), it);

                // pref[idx - 1] gives the total number of marks completely residing in previous intervals
                long long before = pref[idx - 1];

                // Calculate position relative to the current interval's starting mark
                long long offset = q - before - 1;

                ans.push_back(l[idx - 1] + offset);
            }
        }

        return ans;
    }
};