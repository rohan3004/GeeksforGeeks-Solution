#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n = a.size();
        int m = b.size();

        // Ensure we always binary search on the smaller array
        if (n > m) {
            return kthElement(b, a, k);
        }

        // Binary Search range on the number of elements we pick from array 'a'
        // Low: If k > m, we MUST pick at least (k - m) elements from 'a'. Otherwise 0.
        // High: We can pick at most 'n' elements or 'k' elements (if k < n).
        int low = max(0, k - m);
        int high = min(k, n);

        while (low <= high) {
            int cut1 = (low + high) >> 1; // Elements taken from a
            int cut2 = k - cut1;          // Remaining elements taken from b

            // Determine values at the edges of the partition
            // If we pick 0 elements from a, l1 is -infinity
            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1]; 
            // If we pick 0 elements from b, l2 is -infinity
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            // If we pick all elements from a, r1 is +infinity
            int r1 = (cut1 == n) ? INT_MAX : a[cut1];
            // If we pick all elements from b, r2 is +infinity
            int r2 = (cut2 == m) ? INT_MAX : b[cut2];

            // Check if the partition is valid
            if (l1 <= r2 && l2 <= r1) {
                // We found the correct partition. 
                // Since the combined left half has size k, the max element there is the kth element.
                return max(l1, l2);
            }
            else if (l1 > r2) {
                // We took too many elements from 'a', move left
                high = cut1 - 1;
            }
            else {
                // We took too few elements from 'a', move right
                low = cut1 + 1;
            }
        }

        return 1; // Should not reach here
    }
};