#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        if (n == 0) return 0;

        // Step 1: Find the index of the minimum element (the pivot)
        // using Binary Search.
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // If mid element is greater than high element, 
            // the minimum is in the right half.
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                // Otherwise, the minimum is in the left half (including mid).
                high = mid;
            }
        }
        int min_idx = low;

        int count = 0;

        // Step 2: Count elements <= x in the left sorted subarray [0 ... min_idx - 1]
        if (min_idx > 0) {
            // upper_bound returns the first element strictly > x
            auto it1 = upper_bound(arr.begin(), arr.begin() + min_idx, x);
            // The difference gives the number of elements <= x
            count += distance(arr.begin(), it1);
        }

        // Step 3: Count elements <= x in the right sorted subarray [min_idx ... n - 1]
        auto it2 = upper_bound(arr.begin() + min_idx, arr.end(), x);
        count += distance(arr.begin() + min_idx, it2);

        return count;
    }
};