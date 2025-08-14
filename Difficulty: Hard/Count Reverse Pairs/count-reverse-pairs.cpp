class Solution {
public:
    /**
     * @brief The main function that initiates the merge sort process.
     * @param arr The input vector of integers.
     * @return The total count of reverse pairs.
     */
    int countRevPairs(vector<int> &arr) {
        if (arr.empty()) {
            return 0;
        }
        // Call the recursive merge sort helper function on the entire array.
        return mergeSort(arr, 0, arr.size() - 1);
    }

private:
    /**
     * @brief Merges two sorted subarrays and counts the reverse pairs between them.
     * @param arr The array being sorted.
     * @param low The starting index of the first subarray.
     * @param mid The ending index of the first subarray.
     * @param high The ending index of the second subarray.
     * @return The count of reverse pairs spanning the two subarrays.
     */
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // Temporary vector to store the sorted part
        int left = low;   // Pointer for the left half
        int right = mid + 1; // Pointer for the right half

        // Standard merge logic to sort the array
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // Copy remaining elements from the left half, if any
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // Copy remaining elements from the right half, if any
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy the sorted elements from temp back to the original array
        for (int i = low; i <= high; ++i) {
            arr[i] = temp[i - low];
        }
    }

    /**
     * @brief Recursively sorts the array and counts reverse pairs.
     * @param arr The array to be sorted.
     * @param low The starting index of the current segment.
     * @param high The ending index of the current segment.
     * @return The total count of reverse pairs in the segment [low, high].
     */
    int mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) {
            return 0; // Base case: if the array has 0 or 1 element, no pairs exist.
        }

        int mid = low + (high - low) / 2;
        int count = 0;

        // Count pairs from the left and right halves recursively
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);

        // Count pairs that span across the two halves
        int right_ptr = mid + 1;
        for (int i = low; i <= mid; ++i) {
            // Use 2LL to cast to long long and prevent integer overflow
            while (right_ptr <= high && arr[i] > 2LL * arr[right_ptr]) {
                right_ptr++;
            }
            count += (right_ptr - (mid + 1));
        }

        // Finally, merge the two sorted halves
        merge(arr, low, mid, high);

        return count;
    }
};