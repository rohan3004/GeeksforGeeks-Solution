class Solution {
  public:
    // Helper function to merge two halves and count split inversions
    long long mergeAndCount(vector<int> &arr, int left, int mid, int right) {
        vector<int> temp; // Temporary vector to store sorted elements
        int i = left;     // Pointer for left subarray
        int j = mid + 1;  // Pointer for right subarray
        long long count = 0; 

        // Compare elements from both subarrays
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                // No inversion, simply pick the smaller element
                temp.push_back(arr[i++]);
            } else {
                // Inversion found: arr[i] > arr[j]
                // Since left part is sorted, all elements from i to mid are > arr[j]
                count += (mid - i + 1);
                temp.push_back(arr[j++]);
            }
        }

        // Copy remaining elements from the left subarray
        while (i <= mid) {
            temp.push_back(arr[i++]);
        }

        // Copy remaining elements from the right subarray
        while (j <= right) {
            temp.push_back(arr[j++]);
        }

        // Copy back the sorted elements to the original array
        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }

        return count;
    }

    // Recursive function to sort and count inversions
    long long mergeSortAndCount(vector<int> &arr, int left, int right) {
        long long count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            // Count inversions in left half
            count += mergeSortAndCount(arr, left, mid);

            // Count inversions in right half
            count += mergeSortAndCount(arr, mid + 1, right);

            // Count split inversions while merging
            count += mergeAndCount(arr, left, mid, right);
        }
        return count;
    }

    // Main function
    int inversionCount(vector<int> &arr) {
        // We use long long internally to prevent overflow, as N=10^5 
        // can produce ~5 billion inversions (exceeding int limit).
        // However, the function signature requires returning int.
        return (int)mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};