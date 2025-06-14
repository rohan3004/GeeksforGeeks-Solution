#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& arr, int k) {
        int lo = 1;
        int hi = *max_element(arr.begin(), arr.end());
        // binary search for the smallest d in [1..hi]
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            // compute the sum of ceil(arr[i] / mid)
            long long sum = 0;
            for (int x : arr) {
                // (x + mid - 1) / mid is exactly ceil(x/mid)
                sum += (x + mid - 1LL) / mid;
                // early exit if sum already exceeding k
                if (sum > k) break;
            }
            if (sum <= k) {
                // mid works, try smaller
                hi = mid;
            } else {
                // mid too small (sum too large), must increase divisor
                lo = mid + 1;
            }
        }
        return lo;
    }
};
