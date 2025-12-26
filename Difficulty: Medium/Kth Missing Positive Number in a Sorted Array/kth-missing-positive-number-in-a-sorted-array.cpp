class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        // Binary Search to find the position
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                // If missing numbers are fewer than k, the answer is to the right
                low = mid + 1;
            } else {
                // If missing numbers are >= k, the answer is to the left
                high = mid - 1;
            }
        }

        // The answer is derived from the low index
        return low + k;
    }
};