class Solution {
public:
    int countSubset(vector<int> &arr, int k) {
        int n = arr.size();
        int mid = n / 2;

        vector<long long> leftSums, rightSums;

        // Generate subset sums for left half
        for (int mask = 0; mask < (1 << mid); mask++) {
            long long sum = 0;
            for (int i = 0; i < mid; i++) {
                if (mask & (1 << i))
                    sum += arr[i];
            }
            leftSums.push_back(sum);
        }

        // Generate subset sums for right half
        for (int mask = 0; mask < (1 << (n - mid)); mask++) {
            long long sum = 0;
            for (int i = 0; i < (n - mid); i++) {
                if (mask & (1 << i))
                    sum += arr[mid + i];
            }
            rightSums.push_back(sum);
        }

        // Sort right sums for binary search
        sort(rightSums.begin(), rightSums.end());

        long long count = 0;

        // For each left sum, find how many right sums make total k
        for (long long s : leftSums) {
            long long target = k - s;
            auto range = equal_range(rightSums.begin(), rightSums.end(), target);
            count += (range.second - range.first);
        }

        return (int)count;
    }
};
