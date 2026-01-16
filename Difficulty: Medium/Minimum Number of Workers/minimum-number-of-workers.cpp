class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> intervals;

        // Step 1: Build intervals
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int L = max(0, i - arr[i]);
                int R = min(n - 1, i + arr[i]);
                intervals.push_back({L, R});
            }
        }

        // Step 2: Sort by starting time
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int currEnd = 0;
        int i = 0;

        // Step 3: Greedy covering
        while (currEnd < n) {
            int farthest = currEnd;

            while (i < intervals.size() && intervals[i].first <= currEnd) {
                farthest = max(farthest, intervals[i].second + 1);
                i++;
            }

            // No progress → impossible
            if (farthest == currEnd)
                return -1;

            count++;
            currEnd = farthest;
        }

        return count;
    }
};
