class Solution {
public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();
        long long current_sum = 0;

        // Calculate the sum of the first window of size m
        for (int i = 0; i < m; ++i) {
            current_sum += arr[i];
        }

        long long max_sum = current_sum;

        // Slide the window around the circular array
        for (int i = 1; i < n; ++i) {
            // Subtract the element that falls out of the window 
            // and add the new element that comes into the window
            current_sum = current_sum - arr[i - 1] + arr[(i + m - 1) % n];

            // Update the maximum sum found so far
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }

        return max_sum;
    }
};