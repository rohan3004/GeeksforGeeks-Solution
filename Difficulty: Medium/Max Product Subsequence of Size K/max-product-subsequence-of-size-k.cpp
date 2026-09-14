#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        long long ans = 1;

        // Special Case: If k is odd and all elements are negative (or 0), 
        // the max product will inevitably be negative or zero.
        // To maximize it, we must pick the elements with the smallest absolute values (closest to 0).
        if (k % 2 != 0 && arr[n - 1] <= 0) {
            for (int i = n - 1; i >= n - k; i--) {
                ans *= arr[i];
            }
            return ans;
        }

        int left = 0;
        int right = n - 1;

        // If k is odd, we take the largest element to ensure our subsequent pairs 
        // are maximizing a positive product.
        if (k % 2 != 0) {
            ans = arr[right];
            right--;
            k--;
        }

        // Process the remaining elements in pairs
        while (k > 0) {
            long long left_pair = (long long)arr[left] * arr[left + 1];
            long long right_pair = (long long)arr[right] * arr[right - 1];

            // Greedily pick the pair that yields the larger product
            if (left_pair > right_pair) {
                ans *= left_pair;
                left += 2;
            } else {
                ans *= right_pair;
                right -= 2;
            }
            k -= 2;
        }

        return ans;
    }
};