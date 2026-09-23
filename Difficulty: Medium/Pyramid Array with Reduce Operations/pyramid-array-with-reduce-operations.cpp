class Solution {
public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> left(n);
        vector<int> right(n);

        // Calculate maximum valid left slope ending at each index
        left[0] = min(arr[0], 1);
        for (int i = 1; i < n; i++) {
            left[i] = min(arr[i], left[i - 1] + 1);
        }

        // Calculate maximum valid right slope starting at each index
        right[n - 1] = min(arr[n - 1], 1);
        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(arr[i], right[i + 1] + 1);
        }

        long long max_h = 0;
        long long total_sum = 0;

        // Find the maximum peak height and the sum of all elements in the array
        for (int i = 0; i < n; i++) {
            max_h = max(max_h, (long long)min(left[i], right[i]));
            total_sum += arr[i];
        }

        // The cost is total sum of the array minus the sum of the best pyramid
        long long cost = total_sum - (max_h * max_h);

        return cost;
    }
};