class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            // Calculate mid to avoid potential integer overflow
            int mid = low + (high - low) / 2;

            if (arr[mid] == k) {
                return mid; // Target found
            } 
            else if (arr[mid] < k) {
                low = mid + 1; // Target is in the right half
            } 
            else {
                high = mid - 1; // Target is in the left half
            }
        }

        // If not found, 'low' is the correct insertion point
        return low;
    }
};