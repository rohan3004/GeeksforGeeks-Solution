class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= arr[high]) {
                // Minimum is in left part (including mid)
                high = mid;
            } else {
                // Minimum is in right part
                low = mid + 1;
            }
        }

        // low == high -> index of minimum element
        return low;
    }
};
