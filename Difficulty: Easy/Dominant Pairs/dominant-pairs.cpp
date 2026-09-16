class Solution {
public:
    int dominantPairs(vector<int> &arr) {
        int n = arr.size();
        int half = n / 2;

        // Sort the first half and the second half independently
        sort(arr.begin(), arr.begin() + half);
        sort(arr.begin() + half, arr.end());

        int count = 0;
        int j = half;

        // Use two pointers to count the valid pairs
        for (int i = 0; i < half; i++) {
            // Increment the right pointer 'j' as long as the condition holds
            while (j < n && arr[i] >= 5 * arr[j]) {
                j++;
            }
            // All elements from 'half' up to 'j - 1' are valid for the current arr[i]
            count += (j - half);
        }

        return count;
    }
};